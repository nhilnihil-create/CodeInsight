#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n,m,ans=0;
    cin >> n >> m;
    string s;
    for(int i=n; i<=m; i++)
    {
        s=to_string(i);
        if(s[0]==s[4]&&s[1]==s[3])
            ans++;
    }
    cout << ans << endl;
}
