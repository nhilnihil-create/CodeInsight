// https://atcoder.jp/contests/abc118/tasks/abc118_b
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
    vector<int> K(N);
    vector<vector<int>> A(N, vector<int>());
    REP(row, N)
    {
        cin >> K[row];
        REP(col, K[row])
        {
            int a;
            cin >> a;
            --a;
            A[row].push_back(a);
        }
    }
    vector<int> res(M, 0);
    REP(row, N)
    {
        REP(col, K[row])
        {
            ++res[A[row][col]];
        }
    }
    int ans = 0;
    REP(i, M)
    {
        if (res[i] == N) ++ans;
    }
    cout << ans << endl;
    return 0;
}
