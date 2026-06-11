//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define y2 azdfsdgwre

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 2003;
int n, a[N];
bitset <2000001> dp;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n;
    dp[0] = 1;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
        dp |= (dp << a[i]);
    }
    if (n == 1) {
        cout << a[1];
        return 0;
    }
    int pos = total / 2;
    if (total & 1) {
        total++;
    }
    for (int i = total / 2; i <= 2000000; i++) {
        if (dp[i]) {
            cout << i;
            return 0;
        }
    }
}
