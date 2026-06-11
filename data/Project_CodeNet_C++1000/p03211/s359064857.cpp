#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
    string s;
    cin>>s;
    ll ans=INT_MAX;
    for(int i=0;i<s.size()-2;i++)
    {
        string ss;
        ss+=s[i];
        ss+=s[i+1];
        ss+=s[i+2];
        ll x=stoi(ss);
        ll ok=abs(753-x);
        ans=min(ans,ok);
    }
    cout<<ans<<endl;
}
