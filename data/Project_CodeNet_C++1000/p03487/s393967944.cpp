
#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
int main()
{
    map<int,int>m;
    int t,i,ans=0;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        int a;
        cin>>a;
        m[a]++;
    }
    for(auto u:m)
    {
        if(u.second>=u.first)ans+=u.second-u.first;
        else ans+=u.second;
    }
    cout<<ans<<endl;
    return 0;
}
