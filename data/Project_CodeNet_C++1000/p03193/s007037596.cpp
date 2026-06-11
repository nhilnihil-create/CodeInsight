#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    ll n, h, w; cin >> n >> h >> w;
    ll ans = 0;
    rep(i, n) {
        ll a, b; cin >> a >> b;
        if(a >= h && b >= w) ans++;
    }
    print(ans);
}

