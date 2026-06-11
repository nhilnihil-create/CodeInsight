
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int a[N];
ii p[N];
int n, m;
ll sum;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> p[j].second >> p[j].first;
    }
    sort(a, a + n);
    sort(p, p + m, greater<ii>());
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (p[j].second == 0) ++j;
        while (a[i] >= p[j].first && j < m) ++j;
        if (j < m) {
            sum += p[j].first;
            --p[j].second;
        } else {
            sum += a[i];
        }
    }
    cout << sum << endl;

    return 0;
}

