#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,K; cin>>N>>K;
    int v[2*N];
    rep(i,N)cin>>v[i];
    rep(i,N)v[i+N]=v[i];
    int ans=0;
    rep(i,min(N,K)+1){
        vector<vector<int>> G(200);
        rep(j,i+1){
            rep(k,i){
                G[j].push_back(v[N-j+k]);
            }
            sort(G[j].begin(),G[j].end());
            rep(k,min(K-i,i)+1){
                int cnt=0;
                rep(l,i-k){
                    cnt+=G[j][k+l];
                }
                ans=max(ans,cnt);
            }
            rep(k,i){
                G[j].pop_back();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}