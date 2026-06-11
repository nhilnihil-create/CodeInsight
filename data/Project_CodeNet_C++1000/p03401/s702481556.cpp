#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int n; cin >> n;
    vector<int> a(n + 2);
    a[0] = 0; a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int all = 0;
    for (int i = 0; i <= n; i++) {
        all += abs(a[i] - a[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        int sum = all - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) + abs(a[i - 1] - a[i + 1]);
        printf("%d\n", sum);
    }
    return 0;
}