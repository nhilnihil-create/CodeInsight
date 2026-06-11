#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

string s;
bool finished;

void dfs(int i, string t)
{
    if (finished)
        return;
    if (i == 3)
    {
        int sum = s[0] - '0';
        int cnt = 0;
        rep(j, 3)
        {
            if (t[j] == '+')
            {
                sum += s[++cnt] - '0';
            }
            else
            {
                sum -= s[++cnt] - '0';
            }
        }
        if (sum == 7)
        {
            string ans;
            rep(j, 3)
            {
                ans += s[j];
                ans += t[j];
            }
            ans += s.back();
            ans += "=7";
            cout << ans << endl;
            finished = true;
        }
        return;
    }
    dfs(i + 1, t + "+");
    dfs(i + 1, t + "-");
}

void solve()
{
    cin >> s;
    dfs(0, "");
}

int main()
{
    solve();
    return 0;
}