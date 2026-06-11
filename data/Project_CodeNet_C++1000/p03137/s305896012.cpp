// https://atcoder.jp/contests/abc117/tasks/abc117_c
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    REP(i, M) cin >> X[i];
    if (M <= N)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(X.begin(), X.end());
    vector<int> d(M - 1);
    REP(i, M - 1)
    {
        d[i] = X[i + 1] - X[i];
    }
    ll ans = 0;
    sort(d.begin(), d.end());
    int cntd = M - N;
    REP(i, cntd)
    {
        ans += d[i];
    }
    cout << ans << endl;
    return 0;
}
