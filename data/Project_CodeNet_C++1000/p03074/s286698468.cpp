#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int temp = 1;
    vector<ll> acc;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 & s[i] == '0')
        {
            acc.push_back(0);
        }
        if (i == n - 1)
        {
            acc.push_back(temp);
            if (s[i] == '0')
            {
                acc.push_back(0);
            }
            continue;
        }
        if (s[i] == s[i + 1])
        {
            temp++;
        }
        else
        {
            acc.push_back(temp);
            temp = 1;
        }
    }

    vector<ll> acc2(acc.size() + 1);
    for (int i = 0; i < acc.size(); i++)
    {
        acc2[i + 1] = acc[i] + acc2[i];
    }
    ll ans = -1;
    for (int i = 0; i < acc2.size(); i += 2)
    {
        int right = min(i + 2 * k + 1, int(acc2.size() - 1));
        ans = max(ans, acc2[right] - acc2[i]);
    }
    cout << ans << endl;
    return 0;
}