#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 1000006;
int res[N];

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, k;
    scanf("%d %d", &m, &k);
    if (k > (1 << m) - 1) return printf("-1"), 0;
    int n = 1 << (m + 1), mx = (1 << m) - 1;
    if (k == 0) {
        for (int i = 0; i <= mx; i++) {
            printf("%d %d ", i, i);
        }
        return 0;
    }
    if (m == 1) return printf("-1"), 0;
    vector <pair <int, int> > v;
    for (int i = 0; i <= mx; i++) {
        if ((k ^ i) < i) continue;
        v.pb({i, k ^ i});
    }
    pair <int, int> p = v.back();
    v.pop_back();
    res[n/2-1] = p.fi;
    res[n/2] = p.se;
    res[0] = p.fi;
    res[n-1] = p.se;
    int j = 0;
    for (int i = 1; i < n / 2 - 1; i += 2) {
        res[i] = v[j].fi;
        res[i+1] = v[j].se;
        j++;
    }
    j = 0;
    for (int i = n - 2; i > n / 2; i -= 2) {
        res[i] = v[j].fi;
        res[i-1] = v[j].se;
        j++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
