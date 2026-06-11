#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
    int a, b, c,ans;
    vector<int>abc(3);
    rep(i, 3)cin >> abc[i];
    sort(abc.begin(), abc.end());

    a = abc[0], b = abc[1], c = abc[2];
    int diff = (c - a) + (c - b);

    if (diff % 2 == 0)ans = diff / 2;
    else ans = ((diff + 1) / 2) + 1;

    cout << ans << endl;
    return 0;
}