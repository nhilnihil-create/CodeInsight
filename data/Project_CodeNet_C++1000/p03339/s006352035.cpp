#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n);
    int cntW = 0;
    int cntE = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == 'W')
        {
            ans[i] = ans[i - 1] + 1;
        }
        else
        {
            ans[i] = ans[i - 1];
        }
    }

    ll cnt = 0;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (s[i + 1] == 'E')
        {
            cnt++;
        }
        ans[i] += cnt;
    }

    int fans = 300001;

    for (int i = 0; i < n; i++)
    {
        fans = min(fans, ans[i]);
    }
    cout << fans << endl;
}