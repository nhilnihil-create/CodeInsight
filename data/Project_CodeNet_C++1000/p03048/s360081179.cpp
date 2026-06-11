#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int R, G, B, n;
    cin >> R >> G >> B >> n;
    ll ans = 0;
    for(int r = 0; r*R <= n; ++r){
        for(int g = 0; r*R + g*G <= n; ++g){
            if((n - r*R - g*G)%B == 0) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
