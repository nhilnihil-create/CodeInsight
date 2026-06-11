#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define cina(s, n, a) for(int quer = s; quer < n; quer++) cin >> a[quer]
#define mod(a, b) (abs(b) + (a % abs(b))) % abs(b)
#define setp(x) fixed << setprecision(x)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll MOD = 1e9 + 7;
const int N = 100500; // are you sure?

void solve(){
    int a, b, x;
    cin >> a >> b >> x;
    cout << ((x >= a) && (x <= a + b) ? "YES" : "NO");
}

int main(){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}
