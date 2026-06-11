#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string t = "MARCH";
    int n;
    cin >> n;
    map<char, ll>mp;
    while(n--)
    {
        string s;
        cin >> s;
        ++mp[s[0]];
    }
    ll ans = 0;
    for(int i = 0;i < t.size();++i)
        for(int j = i + 1;j < t.size();++j)
            for(int k = j + 1;k < t.size();++k)
                ans += mp[t[i]] * mp[t[j]] * mp[t[k]];
    cout << ans;
    return 0;
}
