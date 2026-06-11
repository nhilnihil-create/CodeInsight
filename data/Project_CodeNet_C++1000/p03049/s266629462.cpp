#include <bits/stdc++.h>

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e3 + 77;

int32_t main()
{
    fast;
    int n;
    cin >> n;
    int ans = 0, a = 0, b = 0, c = 0;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int l = s.length();
        for(int j = 0 ;j < l-1 ; ++j) if(s[j]=='A' && s[j+1]=='B') ans++;
        if(s[0]=='B' && s[l-1]=='A') a++;
        else if(s[0]=='B') b++;
        else if(s[l-1]=='A') c++;
    }
    ans += min(b,c);
    if(b+c>0) ans += a;
    else ans += max(a-1,0ll);
    cout << ans << endl;
    return 0;
}