#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;

int main(void)
{
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int d;
        cin >> d;
        mp[d]++;
    }

    int m;
    cin >> m;

    vector<int> t(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> t[i];
    }

    bool yes = true;
    for (int i = 0; i < m; ++i)
    {
        if (mp[t[i]] == 0)
        {
            yes = false;
            break;
        }

        mp[t[i]]--;
    }

    if (yes)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}