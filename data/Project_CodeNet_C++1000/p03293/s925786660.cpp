#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s,t;
    cin>>s>>t;

    bool ans=false;

    for(int i=0;i<t.size();i++)
    {
        if(s==t)ans=true;

        char ss=s[0];

        for(int j=1;j<s.size();j++)s[j-1]=s[j];
        s[s.size()-1]=ss;
    }

    puts(ans?"Yes":"No");

    return 0;
}
