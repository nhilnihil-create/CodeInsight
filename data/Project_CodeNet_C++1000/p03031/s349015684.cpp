#include <bits/stdc++.h>
using namespace std;

vector<int> levelup(vector<int> v, int N){
    v[N-1]+=1;
    int ind = N-1;
    int j=N-1;
    for(j=N-1;j>=1;j--){
        //cout << j << endl;
        if(v[j]>1){
            v[j-1]+=1;
            v[j]=0;
        }
    }
    /*for(j=0;j<N;j++){
        cout << "v" << v[j];
    }
    cout << endl;*/
    return v;
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int>> ks(M,vector<int>(N,0));
    vector<int> p(M);
    for(int i=0;i<M;i++){
        cin >> k[i];
        for(int j=0;j<k[i];j++){
            cin >> ks[i][j];
        }
    }
    for(int i=0;i<M;i++){
        cin >> p[i];
    }
    int inde = 1;
    for(int i=0;i<N;i++){
        inde *= 2;
    }
    vector<int> vec(N,0);
    int countans=0;
    int count = 0;
    for(int i=0;i<inde;i++){
        for(int j=0;j<M;j++){
            int countt=0;
            for(int l=0;l<k[j];l++){
                if(vec[ks[j][l]-1]==1){
                    //cout << ks[j][l]-1 << endl;
                    countt++;
                    //cout << j <<countt << endl;
                }
                //cout << "j" << j << " " << p[j] << " " <<count << endl;
            }
            if(countt%2==p[j]){
                    count++;
                    //cout << count << endl;
            }
        }
        if(count==M){
            countans++;
        }
        if(i==inde-1){
            break;
        }
        count = 0;
        vec = levelup(vec,N);
    }
    cout << countans << endl;
}