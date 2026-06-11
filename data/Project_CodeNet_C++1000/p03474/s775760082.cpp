#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b;
    cin>>a>>b;

    str s;
    cin>>s;

    bool ans=s.size()==a+b+1;

    for(int i=0;i<s.size();i++)
    {
        if(i==a)ans &= s[i]=='-';
        else ans &= s[i]!='-';
    }

    puts(ans?"Yes":"No");

    return 0;
}
