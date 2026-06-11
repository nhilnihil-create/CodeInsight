#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> ab;
    ll ans = 0;
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        ab.push_back(a+b);
        ans-=b;
    }
    sort(ab.begin(), ab.end(), greater<ll>());

    rep(i,n) {
        if(i%2==0) ans+=ab[i];
    }
    cout << ans << endl;
}
