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

    int cnta=0;
    int cntb=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')cnta++;
        else cntb++;
    }

    cout<<min(cnta,cntb)*2<<"\n";

    return 0;
}
