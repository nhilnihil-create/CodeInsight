#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main()
{
    while(cin>>s)
    {
        ll sum=0;
        sum+=15-int(s.size());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='o') sum++;
        }
        if(sum>=8) cout<<"YES\n";
        else cout<<"NO\n";
    }



}

