#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = int(1e5) + 7;
const int inf = int(1e9);

int n, a[N], t[N];
ll b[N], m;

void Update(int x) {for(; x < N; x += (x & -x)) ++t[x];}
int Get(int x) {int res = 0; for(; x > 0; x -= (x & -x)) res += t[x]; return res;}

bool Check(int k) {
    memset(&t, 0, sizeof t);
    ll cnt = m; vector<int> v;
    for(int i = 1; i <= n; ++i) {
        b[i] = (a[i] >= k) + b[i - 1];
        v.pb(b[i] * 2 - i);
    }
    v.pb(0); sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    Update(lower_bound(v.begin(), v.end(), 0) - v.begin() + 1);
    for(int i = 1; i <= n; ++i) {
        b[i] = lower_bound(v.begin(), v.end(), b[i] * 2 - i) - v.begin() + 1;
        cnt -= Get(b[i]); Update(b[i]);
    }
    return cnt <= 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    if(n == 1) return cout << a[1], 0;
    m = 1ll * n * (n - 1) / 2 + n;
    m = m / 2;
    int low = 1, mid, high = int(1e9);
    while(low <= high) {
       mid = (low + high) >> 1;
       if(Check(mid)) low = mid + 1;
       else high = mid - 1;
    }
    cout << high;
}
