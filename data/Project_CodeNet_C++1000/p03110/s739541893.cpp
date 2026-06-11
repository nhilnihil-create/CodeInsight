#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int n; cin >> n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x; cin >> x;
        string u; cin >> u;
        if (u == "JPY") {
            sum += x;
        } else {
            sum += x * 380000.0;
        }
    }

    printf("%.10lf\n", sum);
    return 0;
}