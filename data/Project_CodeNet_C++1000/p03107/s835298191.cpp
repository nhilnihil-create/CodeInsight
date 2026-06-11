#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    vector<int> sum(2, 0);
    rep(i, (int)s.size()) sum[s[i] - '0']++;

    cout << 2 * min(sum[0], sum[1]) << endl;
}