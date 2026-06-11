#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define Task "A"
#define int long long

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int n, N, a[maxn];
int last[maxn];
ll f[maxn];
ll val[maxn];

signed main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> n;
    while (n--){
        int x;
        cin >> x;
        if (x != a[N]){
            a[++N] = x;
        }
    }
    f[0] = 1;
    for (int i=1; i<=N; ++i){
        f[i] = f[i-1];
        if (last[a[i]] != 0){
            f[i] = (f[i] + val[last[a[i]]]) % mod;
            val[i] = (val[last[a[i]]] + f[i-1]) % mod;
        }
        else{
            val[i] = f[i-1];
        }
        last[a[i]] = i;
    }
    cout << f[N] << '\n';
}
