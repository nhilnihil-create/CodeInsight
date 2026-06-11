// https://atcoder.jp/contests/abc127/tasks/abc127_c
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
    vector<int> L(M), R(M);
    REP(i, M) cin >> L[i] >> R[i];
    int left = -1, right = N;
    REP(i, M)
    {
        left = max(left, L[i]);
        right = min(right, R[i]);
    }
    int ans = right - left >= 0 ? right - left + 1 : 0;
    cout << ans << endl;
    return 0;
}
