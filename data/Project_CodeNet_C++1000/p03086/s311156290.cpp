#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')s[i]='1';
        else if(s[i]=='T')s[i]='1';
        else if(s[i]=='G')s[i]='1';
        else if(s[i]=='C')s[i]='1';
        else s[i]='0';
    }

    int ans=0;
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')cnt++;
        else
        {
            ans=max(ans,cnt);
            cnt=0;
        }
    }
    ans=max(ans,cnt);

    cout<<ans<<"\n";

    return 0;
}
