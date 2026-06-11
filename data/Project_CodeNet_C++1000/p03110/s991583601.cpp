#include<bits/stdc++.h>
using namespace std;
#define  mem(a,x) memset(a,x,sizeof(a));
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pi  pair<int,int>
#define  pb  push_back
#define  F   first
#define  S   second
#define  B   begin()
#define  E   end()
const int N=2e5+3;
//string s,p;
//vector<int>v;
//map<int,int>mp;
int main()
{
    ft
    int n;
    cin>>n;
    double ans=0.0,x;
    string s;
    while(n--)
    {
        cin>>x>>s;
        if(s=="JPY")
        {
            ans+=x;
        }
        else
        {
            ans+=(x*380000.0);
        }
    }
    cout<<ans<<"\n";
    return 0;
}

