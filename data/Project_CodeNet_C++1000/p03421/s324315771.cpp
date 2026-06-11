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

const int N = 3e5 + 123;
int n, a, b;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> a >> b;
    if (n < b) {
        cout << -1;
        return 0;
    }
    vector <int> vec;
    vec.pb(b);
    int x = n - b, y = a - 1;
    while (y > 0) {
        if (x < y) {
            cout << -1;
            return 0;
        }
        int mx = min(b, x - y + 1);
        vec.pb(mx);
        x -= mx;
        y--;
    }
    if (x > 0) {
        cout << -1;
        return 0;
    }
    reverse(all(vec));
    int cur = 1;
    for (auto i : vec) {
        for (int j = cur + i - 1; j >= cur; j--) {
            cout << j << ' ';
        }
        cur += i;
    }
}

