#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define for1(i, a, b) for(i = a; i <= b; ++i)
#define for0(i, a, b) for(i = a; i < b; ++i)
#define forw1(i, a, b) for(i = a; i >= b; --i)
#define forw0(i, a, b) for(i = a - 1; i >= b; --i)
#define fora(v, a) for(auto v : a)
#define bp __builtin_popcount
#define bpll __builtin_popcountll

using namespace std;
using cd = complex<double>;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<cd> vcd;
typedef vector<ii> vii;
typedef vector<vector<int> > vvi;

const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 3e5 + 7;
const double pi = acos(-1);
int fact[maxn], inv[maxn];

int binpow(int a, int b){
    if(b == 0){
        return 1;
    }
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % modd2;
        a = (a * a) % modd2;
        b >>= 1;
    }
    return res;
}

void init(){
    int i;
    fact[0] = 1;
    inv[0] = 1;
    for1(i, 1, maxn){
        fact[i] = (fact[i - 1] * i) % modd2;
        inv[i] = (inv[i - 1] * binpow(i, modd2 - 2)) % modd2;
    }
}

int nCk(int n, int k){
    if(n < k) return 0;
    return (((fact[n] * inv[k]) % modd2) * inv[n - k]) % modd2;
}

void solve(){
    int n, a, b, k, l, r, x, y;
    cin >> n >> a >> b >> k;
    init();
    int ans = 0;
    for1(x, 0, n){
        if((k - x * a) % b == 0){// cout << x << ' ';
            y = (k - x * a) / b; //cout << y << ' ';
            if(y >= 0 && y <= n){
                int temp = (nCk(n, x) * nCk(n, y)) % modd2;
                ans = (ans + temp) % modd2;
            }
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}