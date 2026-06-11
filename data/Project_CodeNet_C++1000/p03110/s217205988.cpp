#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    double x,sumx=0;
    ll suml=0;
    string u;
    rep(i, n) {
        cin >> x >> u;
        if (u == "JPY")suml += x;
        else sumx += x;
    }

    double sums = suml + (sumx * 380000.0);
    cout << fixed << setprecision(16) << sums << endl;
    return 0;
}