#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int a, d,b;
    cin >> a >> d >> b;
    vector<int>mo;
    mo.push_back(b);
    rep(i, 10)mo.push_back((a * mo[i]) - d);
    mo.erase(mo.begin());
    for (auto s: mo)cout << s << endl;
    return 0;
}