#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;
//using std::cin, std::cout, std::endl, std::string;
using ll = long long;

#define rep(countName, left, right, up) for (ll countName = left; countName < right; countName += up)
#define REP(countName, end) for (ll countName = 0; countName < end; countName++)
#define rev(countName, right, left, down) for (ll countName = right - 1; countName >= left; countName -= down)
#define REV(countName, end) for (ll countName = end - 1; countName >= 0; countName--)

int main(void)
{
    std::vector<std::pair<int, int>> v(4);
    for (int i = 0; i < 2; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int x = v[1].first - v[0].first;
    int y = v[1].second - v[0].second;

    //cout << x << " " << y << endl;
    cout << v[1].first - y << " " << v[1].second + x << " ";
    cout << v[0].first - y << " " << v[0].second + x << endl;

    return 0;
}