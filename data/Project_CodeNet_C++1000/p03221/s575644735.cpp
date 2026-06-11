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
    for (int i = 0; i < m; ++i) cin >> p[i] >> y[i];
    map<int, int> dic; // year, cityid
    for (int i = 0; i < m; ++i)
    {
        dic[y[i]] = i;
    }
    map<int, int> order; // p, order
    vector<P> res(m);    // res[i] ... i=cityid, first=p, second=order
    for (auto it = dic.begin(); it != dic.end(); ++it)
    {
        int cityid = it->second;
        res[cityid].first = p[cityid];
        ++order[p[cityid]];
        res[cityid].second = order[p[cityid]];
    }
    for (int i = 0; i < m; ++i)
    {
        cout << setfill('0') << std::right << std::setw(6) << res[i].first;
        cout << setfill('0') << std::right << std::setw(6) << res[i].second << endl;
    }
    return 0;
}
