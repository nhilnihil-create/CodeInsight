#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    sort(p.begin(), p.end());
    int sum = p[n - 1] / 2;
    for (int i = 0; i < n - 1; i++) {
        sum += p[i];
    }
    cout << sum << endl;
    return 0;
}