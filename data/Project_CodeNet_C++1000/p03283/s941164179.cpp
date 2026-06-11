#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M, Q;
    int L,R,p,q;
    int ans(0),sum(0);
    cin >> N >> M >> Q;
    /*
    vector<vector<int>> v,t;
    v.resize(N);
    t.resize(N);
    for (int i = 0; i < N; i++)
    {
        v[i].resize(N);
        t[i].resize(N);
    }*/
    int v[501][501]={};
    int t[501][501]={};
    for (int i = 0; i < M; i++){
        cin >> L >> R;
        t[L][R]++;
    }
    for(int i=1;i<N+1;i++){
        for(int j=1;j<N+1;j++){
            v[i][j]=v[i][j-1]+t[i][j];
        }
    }
    for(int i=0;i<Q;i++){
        cin >> p >> q;
        ans=0;
        for(int j=p;j<=q;j++){
            ans+=v[j][q];
        }
        cout << ans << "\n";
    }
}