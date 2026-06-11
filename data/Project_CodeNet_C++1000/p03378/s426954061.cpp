#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int>gate(m);
    rep(i, m)cin >> gate[i];
    int right = m+1, left = 0,mid;
    while (!(left +1 == right)) {
        mid = (right + left ) / 2;
        if (gate[mid] < x)left = mid;
        else right = mid;
    }
    if (left == 0)cout << 0 << endl;
    else cout << min(left+1, m - right) << endl;
    return 0;
}