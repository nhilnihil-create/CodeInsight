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
    int N, M; cin >> N >> M;
    int ans = 0;
    if (N < M) {
        vector<int> X(M);
        for (int i = 0; i < M; i++) {
            cin >> X.at(i);
        }
        sort(X.begin(), X.end());
        vector<int> dist(M - 1);
        for (int i = 0; i < M - 1; i++) {
            dist.at(i) = X.at(i + 1) - X.at(i);
            ans += dist.at(i);
        }
        sort(dist.begin(), dist.end());
        for (int i = 0; i < N - 1; i++) {
            ans -= dist.at(M - 2 - i);
        }
    }
    cout << ans << endl;
    return 0;
}