#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;
    cin>>s;

    int ans=0;
    int cnt=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T')cnt++;
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
