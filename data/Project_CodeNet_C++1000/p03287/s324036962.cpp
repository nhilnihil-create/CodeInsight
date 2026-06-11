#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    map<ll, ll> mp;
    mp[0] = 1;
    ll cur = 0, ans = 0;
    rep(i,n){
        cin >> a[i];
        cur = (cur + a[i]) % m;
        ans += mp[cur]++;
    }
    cout << ans << endl;
	return 0;
}