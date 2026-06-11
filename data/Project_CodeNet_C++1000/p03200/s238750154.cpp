#include <bits/stdc++.h>
using namespace std;

using str = string;
using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    str s;
    cin>>s;
    
    ll cntb=0;
    ll cntw=0;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='B')cntb++;
        else cntw+=cntb;
    }
    
    cout<<cntw<<"\n";
    
    return 0;
}

