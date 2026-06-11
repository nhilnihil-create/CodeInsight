#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <tuple>
#include <cmath>
#include <map>
using namespace std;
using Int = long long;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n,m) for(int i=n;i<m;i++)
int main()
{
    int N; cin >> N;
    vector<int> A(N);
    vector<pair<int, int>> ops;
    for (auto&& i : A) cin >> i;
    auto m = min_element(A.begin(), A.end());
    auto M = max_element(A.begin(), A.end());
    if (abs(*m) <= abs(*M)) {
        int i = M - A.begin() + 1;
        ops.push_back(make_pair(2, i));
        ops.push_back(make_pair(2, i));
        for (i = 3; i <= N; i++) {
            ops.push_back(make_pair(i, i-1));
            ops.push_back(make_pair(i, i-1));
        }
    } else {
        int i = m - A.begin() + 1;
        ops.push_back(make_pair(N-1, i));
        ops.push_back(make_pair(N-1, i));
        for (i = N-2; i >= 1; i--) {
            ops.push_back(make_pair(i, i+1));
            ops.push_back(make_pair(i, i+1));
        }
    }
    cout << ops.size() << endl;
    for (const auto& op : ops) cout << op.second << ' ' << op.first << '\n';
    return 0;
}