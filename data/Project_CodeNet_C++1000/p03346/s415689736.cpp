#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    ll n;
    cin >> n;
    vector<ll>p(n);
    rep(i,n){
        cin>>p[i];
        p[i]--;
    }
    vector<ll>q(n);
    rep(i,n){
        ll now = p[i];
        q[now] = i;
    }
    ll l = 1;
    ll ans = 1;
    rep(i,n-1){
        if(q[i+1]>q[i]){
            l++;
            chmax(ans,l);
        }
        else{
            l = 1;
            chmax(ans,l);
        }
    }
    cout << n-ans << endl;
    return 0;
}
