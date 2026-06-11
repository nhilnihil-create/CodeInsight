#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

vector<ll>s,t,x;
ll di(ll x){
    int itr1 = lower_bound(s.begin(),s.end(),x)-s.begin();
    int itr2 = lower_bound(t.begin(),t.end(),x)-t.begin();
    ll Rs = s[itr1];
    ll Rt = t[itr2];
    ll Ls = s[itr1-1];
    ll Lt = t[itr2-1];
    ll res = INF;
    chmin(res,x-min(Ls,Lt));
    chmin(res,max(Rs,Rt)-x);
    chmin(res,Rs-Lt+min(Rs-x,x-Lt));
    chmin(res,Rt-Ls+min(Rt-x,x-Ls));
    return res;
}
int main(){
    int a,b,q;
    cin >> a >> b >> q;
    s.resize(a+2);t.resize(b+2);x.resize(q);
    rep(i,a)cin >> s[i+1];
    rep(i,b)cin>>t[i+1];
    rep(i,q)cin>>x[i];
    s[0]=-INF;s[a+1]=INF;
    t[0]=-INF;t[b+1]=INF;
    rep(i,q){
        cout << di(x[i]) << endl;
    }
    return 0;
}
