#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
long long  i,count=0,ans=0;
    for(i=0; i<s.size(); i++)
    {
        if(s[i]=='B')
            count++;
        else if(s[i]=='W')
            ans=ans+count;
    }
    cout<<ans;
}