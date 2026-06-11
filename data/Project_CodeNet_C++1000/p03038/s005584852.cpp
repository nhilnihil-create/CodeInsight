#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int a[100010];
pii b[100010];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].second >> b[i].first;
    }
    sort(b + 1, b + 1 + m, greater<pii>());
    int p = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = p + 1, cnt = 0; j <= n; ++j) {
            if (b[i].first <= a[j]) {
                p = j - 1;                
                break;
            }
            ++cnt;
            a[j] = b[i].first;
            if (cnt == b[i].second) {
                p = j;
                break;
            }
        }
    }
    long long answer = 0;
    for (int i = 1; i <= n; ++i) {
     //   cout << a[i] << " ";
        answer += a[i];
    }
    cout << answer;
}