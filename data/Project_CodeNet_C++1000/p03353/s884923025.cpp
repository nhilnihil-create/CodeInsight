#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    vector<string> vs;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= k; ++j)
            vs.push_back(s.substr(i, j));
    }
    sort(all(vs));
    vs.resize(unique(all(vs)) - vs.begin());
    cout << vs[k - 1];
}
