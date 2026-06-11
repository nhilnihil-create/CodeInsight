#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a, b, c, x,cnt=0;
    cin >> a >> b >> c >> x;
    for (int i = 0; i <= 500 * a; i += 500) {
        for (int j = 0; j <= 100 * b; j += 100) {
            for (int k = 0; k <= 50 * c; k += 50) {
                if ((i + j + k) == x)cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}