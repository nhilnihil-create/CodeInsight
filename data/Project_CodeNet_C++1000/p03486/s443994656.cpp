#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s,t;cin>>s>>t;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<char>());

    int ans=2;
    int i=0;

    for(;i<min(s.size(),t.size());i++)
    {
        if(s[i]<t[i]){ans=1;break;}
        if(s[i]>t[i]){ans=0;break;}
    }

    if(ans==2)
    {
        if(s.size()<t.size())ans=1;
        else ans=0;
    }

    puts(ans?"Yes":"No");

    return 0;
}
