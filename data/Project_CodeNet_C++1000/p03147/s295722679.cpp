#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N; cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) cin >> h.at(i);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int n = N;
        while (h.at(i) != 0) {
            int m = inf;
            for (int j = i; j < N; j++) {
                if (h.at(j) == 0) {
                    n = j;
                    break;
                }
                m = min(m, h.at(j));
            }
            for (int k = i; k < n; k++) h.at(k) -= m;
            ans += m;
        }
    }
    cout << ans << endl;
    return 0;
}