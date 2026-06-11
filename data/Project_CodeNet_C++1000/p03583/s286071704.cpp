#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    int N;
    cin>>N;
    for (int h = 1; h <= 3500; h++) {
        for (int w = 1; w <= 3500; w++) {
            if ((4 * h * w - N * w - N * h) == 0) continue;
            if ((N * h * w) % (4 * h * w - N * w - N * h) == 0 && (N * h * w) / (4 * h * w - N * w - N * h) > 0) {
                int n = (N * h * w) / (4 * h * w - N * w - N * h);
                cout<<h<<' '<<n<<' '<<w<<endl;
                return 0;
            }
        }
    }
}