#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll cnt=0;
    ll sum=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='W')
        {
             cnt++;
             sum+=i;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        sum-=i;
    }
    cout<<sum<<endl;

}
