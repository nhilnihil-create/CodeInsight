#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define sayyes cout<<"Yes"<<endl;
#define sayno cout<<"No"<<endl;
using namespace std;
typedef long long ll;
const double PI=acos(-1);
typedef pair<int,int>P;
const int mod =1e9+7;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    string rs;
    int i=0;
    while(i<n-1)
    {
        if(s[i]=='B' && s[i+1]=='C')
        {
            rs+="D";
            i+=2;
        }
        else
        {
            rs+=s[i];
            i+=1;
        }
        
    }
    ll dc=0;
    ll ans=0;
    for(auto v:rs)
    {
        if(v=='A')
        {
            dc++;
        }
        else if(v=='D')
        {
            ans+=dc;
        }
        else
        {
            dc=0;
        }
        
    }
    cout<<ans;
}
