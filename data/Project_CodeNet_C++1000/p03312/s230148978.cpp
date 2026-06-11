#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+7;
typedef long long LL;
typedef pair< LL , LL >PLL;

vector< PLL >preOptions[MAXN];
vector< PLL >sufOptions[MAXN];
LL a[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    LL total = a[1];
    LL bam = a[1];
    for (int i = 2, j = 1; i <= n; i++) {
        total += a[i];
        while (j+1 < i && bam+a[j+1] <= total-(bam+a[j+1])) {
            j++;
            bam += a[j];
        }
        preOptions[i].emplace_back(bam, total-bam);
        if (j+1 < i) {
            preOptions[i].emplace_back(bam+a[j+1], total-bam-a[j+1]);
        }
    }

    total = a[n];
    LL dan = a[n];
    for (int i = n-1, j = n; i > 0; i--) {
        total += a[i];
        while (j-1 > i && dan+a[j-1] <= total-(dan+a[j-1])) {
            j--;
            dan += a[j];
        }
        sufOptions[i].emplace_back(dan, total-dan);
        if (j-1 > i) {
            sufOptions[i].emplace_back(dan+a[j-1], total-dan-a[j-1]);
        }
    }

    LL ans = 1e18;
    for (int i = 2; i+2 <= n; i++) {
        for (PLL p : preOptions[i]) {
            LL mn = min(p.first, p.second);
            LL mx = max(p.first, p.second);
            for (PLL q : sufOptions[i+1]) {
                LL _mn = min(q.first, q.second);
                LL _mx = max(q.first, q.second);
                ans = min(ans, max(mx, _mx)-min(mn, _mn));
            }
        }
    }

    cout << ans << endl;


    return 0;
}
