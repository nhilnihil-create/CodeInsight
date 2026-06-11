#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    string s,t;
    cin>>s>>t;
    map<char,char> mp,gorl;
    for(unsigned int i=0;i<s.size();i++)
    {
        if(mp[s[i]]>='a'&&mp[s[i]]<='z')
        {
            if(mp[s[i]]!=t[i])
            {
                cout<<"No";
                return 0;
            }
        }
        if(gorl[t[i]]>='a'&&gorl[t[i]]<='z')
        {
            if(gorl[t[i]]!=s[i])
            {
                cout<<"No";
                return 0;
            }
        }
        mp[s[i]]=t[i];
        gorl[t[i]]=s[i];
    }
    cout<<"Yes";
}