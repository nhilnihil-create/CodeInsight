#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;
    int ans=0;
    for(int i=0;i<4;i++)
    {
        if(s[i]=='+')ans++;
        else ans--;
    }

    cout<<ans<<"\n";

    return 0;
}
