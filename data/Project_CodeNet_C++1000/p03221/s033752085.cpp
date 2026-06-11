#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m), y(m);
    vector<vector<int>> yd(n+1);
    for (int i = 0; i < m; ++i) 
    {
        cin >> p[i] >> y[i];
        yd[p[i]].push_back(y[i]);
    }

    for (int i = 0; i < n; ++i) sort(yd[i + 1].begin(), yd[i + 1].end());
    vector<P> res(m);    // res[i] ... i=cityid, first=p, second=order
    for (int i = 0; i < m; ++i)
    {
        res[i].first = p[i];
        res[i].second = 
        std::distance(yd[p[i]].begin(), std::lower_bound(yd[p[i]].begin(), yd[p[i]].end(), y[i])) + 1;
    }

    for (int i = 0; i < m; ++i)
    {
        cout << setfill('0') << std::right << std::setw(6) << res[i].first;
        cout << setfill('0') << std::right << std::setw(6) << res[i].second << endl;
    }
    return 0;
}
