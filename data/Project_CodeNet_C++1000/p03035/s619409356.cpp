#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int a, b;
    cin >> a >> b;
    int res = 0;
    if (a >= 13)res = b;
    else if (a >= 6)res = b / 2;
    cout << res << endl;
    return 0;
}