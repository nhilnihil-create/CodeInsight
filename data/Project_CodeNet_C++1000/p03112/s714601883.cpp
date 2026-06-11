#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll INFL = 1001001001001;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
    int a, b, q;
    cin >> a >> b >> q;
    ll s[100002], t[100002];
    fill(s, s + 100002, INFL);
    fill(t, t + 100002, 2*INFL);
    rep(i, a) cin >> s[i+1];
    rep(i, b) cin >> t[i+1];
    sort(s+1, s + a+1);
    sort(t+1, t + a+1);
    s[0] = -INFL;
    t[0] = -2 * INFL;

    rep(i, q){
        ll x;
        cin >> x;
        auto itrs = lower_bound(s, s + a+2, x);
        auto itrt = lower_bound(t, t + b+2, x);
        
        ll temple_a = *prev(itrt, 1);
        ll temple_b = *itrt;
        ll shrine_a = *prev(itrs, 1);
        ll shrine_b = *itrs;
        ll ans = min(max(shrine_b-x, temple_b-x), max(x-shrine_a, x - temple_a));
        
        if(shrine_a < temple_a && shrine_b < temple_b){
            ans = min(ans, min(2*shrine_b - x - temple_a, shrine_b + x - 2 * temple_a));
        }else if(temple_a < shrine_a && temple_b < shrine_b){
            ans = min(ans, min(2*temple_b - x - shrine_a, x + temple_b - 2 * shrine_a));
        }
        cout << ans << endl;
        
    }
}