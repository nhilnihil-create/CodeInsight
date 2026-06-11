#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF -10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,M;
    cin>>N>>M;
    vector<ll> x(N),y(N),z(N);
    rep(i,N)cin>>x[i]>>y[i]>>z[i];
    ll ans=0;
    rep(bit,(1<<3)){
        vector<ll> res(N,0); 
        rep(i,N){
            if(bit&1)res[i]+=x[i];
            else res[i]-=x[i];
            if(bit&2)res[i]+=y[i];
            else res[i]-=y[i];
            if(bit&4)res[i]+=z[i];
            else res[i]-=z[i];
        }
        sort(res.rbegin(),res.rend());
        ll tmp = 0;
        rep(i,M)tmp+=res[i];
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}
