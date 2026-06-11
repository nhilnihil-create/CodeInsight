#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int H,W; 
    cin>>H>>W;
    int A[H][W];
    rep(i,H){
        rep(j,W){
            cin>>A[i][j];
        }
    }

    vector<int> x,y,nx,ny;
    rep(i,H){
        rep(j,W-1){
            if(A[i][j]%2==1){
                A[i][j]--;
                A[i][j+1]++;
                x.push_back(i+1);
                y.push_back(j+1);
                nx.push_back(i+1);
                ny.push_back(j+2);
            }
        }
    }

    rep(i,H-1){
        if(A[i][W-1]%2==1){
            A[i][W-1]--;
            A[i+1][W-1]++;
            x.push_back(i+1);
            y.push_back(W);
            nx.push_back(i+2);
            ny.push_back(W);
        }
    }

    cout<<x.size()<<endl;
    rep(i,x.size()){
        cout<<x[i]<<" "<<y[i]<<" "<<nx[i]<<" "<<ny[i]<<endl;
    }
}