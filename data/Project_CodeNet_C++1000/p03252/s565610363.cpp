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
#include <set>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string S, T;
    cin >> S >> T;
    int n = S.size();
    vector<int> sdist(26, 0), tdist(26, 0);
    for (int i = 0; i < n; ++i)
    {
        ++sdist[S[i] - 'a'];
        ++tdist[T[i] - 'a'];
    }
    if (sdist.size() != tdist.size())
    {
        cout << "No" << endl;
        return 0;
    }

    sort(sdist.begin(), sdist.end());
    sort(tdist.begin(), tdist.end());
    for (int i = 0; i < 26; ++i)
    {
        if (sdist[i] != tdist[i])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
