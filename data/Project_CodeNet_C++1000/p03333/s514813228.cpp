// Why I am so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;
                 
int l[MAXN], r[MAXN];

ll ans;

int n;

void solve() {                   
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
    }

    sort(l, l + n + 1);
    reverse(l, l + n + 1);
    sort(r, r + n + 1);

    ll cur = 0;
                     
    for (int i = 0; i <= n; ++i) {
        cur += (l[i] - r[i]);
        ans = max(ans, cur << 1);
    }

    printf("%lld\n", ans);
}

int main() {    
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}