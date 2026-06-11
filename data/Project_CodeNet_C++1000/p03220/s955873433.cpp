#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, t, a,h,bestn;
    double tmp = 0.0,besttmp=10000000;
    cin >> n >> t >> a;
    rep(i, n) {
        cin >> h;
        tmp = t - h * 0.006;
        if (abs(a - tmp) < besttmp) {
            besttmp = abs(a - tmp);
            bestn = i + 1;
        }
    }
    cout << bestn << endl;

    return 0;
}