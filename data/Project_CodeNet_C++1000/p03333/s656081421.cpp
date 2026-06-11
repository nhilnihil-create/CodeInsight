// Why am I so dumb? :c
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

int cl[MAXN], cr[MAXN];

ll ans;

int n;

void solve() {                   
	scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
    	scanf("%d %d", &cl[i], &cr[i]);
    }

    /*
    cl[n + 1] = cr[n + 1] = 0;
    ++n;
    */

    sort(cl + 1, cl + n + 1);
    sort(cr + 1, cr + n + 1);
    reverse(cl + 1, cl + n + 1);

    ll sum = 0;       

    /*
    5 3 1 0
    0 2 4 6
    */

    for (int i = 1; i <= n; ++i) {
    	ans = max(ans, sum + cl[i]);
    	ans = max(ans, sum - cr[i]);
    	ans = max(ans, sum + cl[i] - cr[i]);
    	sum += (cl[i] - cr[i]);
    } 

    printf("%lld\n", ans * 2);
}

int main() {    
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}