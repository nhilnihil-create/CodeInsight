#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    ll a,b;
    cin >> a >> b;
    ll x = b/4;
    ll y = b%4;
    ll xorsum_b=0;
    rep(i,y+1) {
        xorsum_b ^= 4*x+i;
    }
    ll xorsum_a = 0;
    x = (a-1)/4;
    y = (a-1)%4;
    rep(i,y+1) {
        xorsum_a ^= 4*x+i;
    }
    ll ans = xorsum_a ^ xorsum_b;
    cout << ans << endl;
}