#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int main() {
    int H, W, D;
    cin>>H>>W>>D;
    map<int, pair<int, int> > A;
    int tmp;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            cin>>tmp;
            tmp--;
            A[tmp] = make_pair(i, j);
        }
    }
    int sum[D][H*W/D+1];
    for(int i=0;i<D;++i){
        for(int j=0;j<H*W/D+1;++j){
            if(j==0)sum[i][j]=0;
            else{
                if(i+j*D >= H*W) sum[i][j] = 0;
                else sum[i][j] = sum[i][j-1] + abs(A[i+j*D].first - A[i+(j-1)*D].first) + abs(A[i+j*D].second - A[i+(j-1)*D].second);
            }
        }
    }
    /**
    for(int i=0;i<D;++i){
        for(int j=0;j<H*W/D+1;++j){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    **/
    int Q;
    cin>>Q;
    int L, R;
    for(int i=0;i<Q;++i){
        cin>>L>>R;
        L--;
        R--;
        cout<<sum[R%D][R/D] - sum[L%D][L/D]<<endl;
    }
}
