#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)

int main(void){
    int n,m;
    cin>>n>>m;
    Graph G(m);
    rep(i,m){
        int k;
        cin>>k;
        rep(j,k){
            int s;
            cin>>s;
            s--;
            G[i].push_back(s);
        }
    }
    vector<int> P(m);
    rep(i,m) cin>>P[i];
    int ans=0;
    rep(bit,(1<<n)){
        int sum=0;
        rep(i,m){
            int temp=0;
            for(auto j:G[i]){
                if(bit&(1<<j)) temp++;
            }
            if(temp%2==P[i]) sum++;
        }
        //cout<<bit<<" "<<sum<<endl;
        if(sum==m) ans++;
    }
    cout<<ans<<endl;
    return 0;
}