#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5;
ll bit[N+1];

void upd(int k, ll val) {
    for (; k <= N; k += k&-k) bit[k] = max(bit[k], val);
}

ll rmq(int k) {
    ll mx = 0;
    for (; k >= 1; k -= k&-k) mx = max(mx, bit[k]);
    return mx;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    
    int h[n], w[n];
    forn(i, 0, n) cin >> h[i];
    forn(i, 0, n) cin >> w[i];
    
    ll ans = 0;
    forn(i, 0, n) {
        ll mx = rmq(h[i]-1);
        ll dpi = mx + w[i];
        upd(h[i], dpi);
        
        ans = max(ans, dpi);
    }
    
    cout << ans << endl;
}
