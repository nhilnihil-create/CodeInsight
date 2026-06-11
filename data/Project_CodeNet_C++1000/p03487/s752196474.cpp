#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    long long ans = 0;
    for (auto p : mp)
    {
        int id = p.first;
        int num = p.second;
        if (num < id)
            ans += num;
        else
            ans += num - id;
    }
    cout << ans << endl;

    return 0;
}