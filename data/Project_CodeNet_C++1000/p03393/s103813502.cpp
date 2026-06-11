#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int a[26];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    str s;cin>>s;

    for(int i=0;i<s.size();i++)a[s[i]-'a']++;

    if(s.size()==26)
    {
        for(int i=s.size()-1;i>=0;i--)
        {
            int j=s[i]-'a';
            for(;j<26;j++)if(a[j]==0)
            {
                s[i]=j+'a';break;
            }

            if(j==26)
            {
                a[s[i]-'a']--;
                s[i]='A';
            }
            else break;
        }
    }
    else
    {
        for(int i=0;i<26;i++)if(a[i]==0){s.push_back(i+'a');break;}
    }
    

    if(s[0]=='A')cout<<-1;
    else for(int i=0;i<s.size();i++)
    {
        if(s[i]=='A')break;
        cout<<s[i];
    }

    cout<<"\n";

    return 0;
}
