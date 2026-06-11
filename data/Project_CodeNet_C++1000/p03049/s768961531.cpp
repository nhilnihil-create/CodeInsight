#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    ll ans = 0;
    ll endA = 0, stB = 0, both = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        endA += (str[i].back() == 'A');
        stB += (str[i].front() == 'B');
        both += (str[i].back() == 'A') && (str[i].front() == 'B');
        for (int j = 0; j < str[i].size() - 1; j++)
        {
            if (str[i][j] == 'A' && str[i][j + 1] == 'B')
            {
                ans++;
            }
        }
    }
    if (both > 1)
    {
        {
            ans += both - 1;
        }
        endA -= both;
        stB -= both;
        if (endA > 0)
        {
            ans++;
            endA--;
        }
        if (stB > 0)
        {
            ans++;
            stB--;
        }
        cout << ans + min(stB, endA) << endl;
    }
    else
    {
        cout << ans + min(endA, stB) << endl;
    }
}
