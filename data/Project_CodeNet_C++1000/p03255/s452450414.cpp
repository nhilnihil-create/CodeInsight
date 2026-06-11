#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
const ll MAX_VAL = (ll) 1e18;
ll pref[MAX];
int arr[MAX];
int n, x;

bool overflow(ll a, ll b) {
    return a > MAX_VAL / b;
}

int main() {
    scanf("%d %d", &n, &x);
    fori(i, 1, n + 1) {
        scanf("%d", arr + i);
        pref[i] = pref[i - 1] + arr[i];
    }
    ll ans = MAX_VAL;
    fori(i, 1, n + 1) { // group size
        ll cur = 1LL * i * x;
        int index = n;
        int it = 0;
        do {
            ll coef = it == 0 ? 5 : (3 + 2 * it);
            if(overflow(pref[index] - pref[max(0, index - i)], coef)) {
                cur = MAX_VAL;
                break;
            }
            cur += (pref[index] - pref[max(0, index - i)]) * coef;
            index -= i;
            it++;
        } while(index >= 1 && cur <= MAX_VAL);
        ans = min(ans, cur);
    }
    ans += 1LL * n * x;
    printf("%lld\n", ans);
    return 0;
}
