#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n) cin >> a[i];
    vector<ll>d(n+1);
    map<ll,ll>mp;
    mp[0] = 1;
    ll ans = 0;
    rep(i,n) {
        d[i+1] = d[i] + a[i];
        ans += mp[d[i+1]];
        mp[d[i+1]]++;
    }
    cout << ans << endl;
    
}
    


