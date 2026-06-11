#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> P(m), Y(m);
    rep(i, m) cin >> P[i] >> Y[i];

    vector<vector<int>> vals(n + 1);
    rep(i, m) vals[P[i]].push_back(Y[i]);
    rep(i, n + 1) sort(vals[i].begin(), vals[i].end());

    rep(i, m)
    {
        printf("%06d", P[i]);
        int id = lower_bound(vals[P[i]].begin(), vals[P[i]].end(), Y[i]) - vals[P[i]].begin();
        printf("%06d\n", id + 1);
    }
}