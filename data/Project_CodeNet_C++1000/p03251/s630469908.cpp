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
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    vector<int> x(N), y(M);
    int xM = -inf, ym = inf;
    for (int i = 0; i < N; i++) {
        cin >> x.at(i);
        xM = max(xM, x.at(i));
    }
    for (int i = 0; i < M; i++) {
        cin >> y.at(i);
        ym = min(ym, y.at(i));
    }
    string ans = "War";
    for (int Z = X + 1; Z <= Y; Z++) {
        if (Z > xM && Z <= ym) {
            ans = "No War";
            break;
        }
    }
    cout << ans << endl;
}