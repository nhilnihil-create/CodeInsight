#include<bits/stdc++.h>
#include<string>

using namespace std;


int main()
{
long long temp,ans,i;
string s;
cin>>s;
for(i=0,temp=0,ans=0;i<s.size();i++)
{
    if(s[i]=='A')
    {
        temp++;
    }
    else if(s[i]=='B')
    {
        if(i+1<s.size()&&s[i+1]=='C')
        {
            ans+=temp;
            i++;
        }
        else
            temp=0;

    }else temp=0;

}
    cout<<ans;
}
