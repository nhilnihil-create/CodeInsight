#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    rep(i, n)
    {
        cin >> a[i];
    }

    rep(i, n)
    {
        mp[a[i]]++;
    }
    int ans = 0;
    for (auto p : mp)
    {
        int x = p.first;
        int cnt = p.second;
        if (cnt < x)
        {
            ans += cnt;
        }
        else
        {
            ans += cnt - x;
        }
    }
    cout << ans << endl;
    return 0;
}
