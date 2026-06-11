#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
string s;
vector <int> ans;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> s;
    N = s.length();
    bool bad = false;
    if (s[0] == '0') bad = true;
    if (s[N-1] == '1') bad = true;
    for (int i = 0; i < N; i++)
    {
        if (i < N - 1 && s[i] != s[N-2-i])
            bad = true;
        if (s[i] == '1')
            ans.push_back (i + 1);
    }

    if (bad)
    {
        cout << "-1\n";
        return 0;
    }

    int ctot = 1;
    for (int x : ans)
    {
        cout << ctot << " " << ctot + 1 << "\n";
        ctot++;
    }

    for (int i = 0; i + 1 < ans.size(); i++)
    {
        int nd = ans[i+1] - ans[i] - 1;
        for (int j = 0; j < nd; j++)
        {
            cout << ctot + 1 << " " << i + 2 << "\n";
            ctot++;
        }
    }
}