#include<bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
using Graph = vector<vector<int>>;

int main(){
    int N,X; cin>>N>>X;
    ll res = 0;
    vector<ll> m(N);
    rep(i,N){
        cin>>m[i];
        res += m[i];
    }
    ll ans = N;
    sort(m.begin(),m.end());
    ans += (X-res)/m[0];
    cout<<ans<<endl;
}
