#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int a, b,sum=0;
    cin >> a >> b;
    rep(i, 2) {
        if (a > b) {
            sum += a;
            a--;
        }
        else {
            sum += b;
            b--;
        }
    }
    cout << sum << endl;
    return 0;
}