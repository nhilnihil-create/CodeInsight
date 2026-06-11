#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

str key="keyence";

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;

    int fk=0;

    for(;fk<7;fk++)if(s[fk]!=key[fk])break;

    int bk=0;

    for(;bk<7;bk++)if(s[s.size()-1-bk]!=key[7-1-bk])break;

    bool ans=fk+bk>=7;

    puts(ans?"YES":"NO");

    return 0;
}
