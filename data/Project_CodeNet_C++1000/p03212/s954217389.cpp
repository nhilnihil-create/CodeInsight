#include <bits/stdc++.h>
using ll = long long;
using namespace std;

set<int> st;
int n;
void dfs(int x)
{
    ll y = 1LL * 10 * x + 3;
    if (y > n)
        return;
    for (int i = 0; i < 5; i += 2)
        st.insert(y + i), dfs(y + i);
}
int main(void)
{
    cin >> n;
    dfs(0);
    int ans = 0;
    for (auto i : st)
    {
        int j = i;
        map<int, int> mp;
        while (j > 0)
            mp[j % 10]++, j /= 10;
        if (mp[3] == 0 || mp[5] == 0 || mp[7] == 0)
            continue;
        if (i <= n)
            ans++;
    }
    cout << ans << endl;
}
