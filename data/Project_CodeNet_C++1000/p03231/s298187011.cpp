#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#include<set>
#include<iomanip>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<double,double>P;

ll gcd(ll a,ll b)
{
    if(a!=0 && b==0)
    {
        return a;
    }
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return(gcd(b,a%b));
    }
    
}

ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s;
    cin>>t;
    ll d=gcd(n,m);
    ll l=lcm(n,m);
    ll nx=l/n;
    ll mx=l/m;
    bool flag=true;
    ll x=lcm(nx,mx);
    ll j=0;
    while(j<l)
    {
       // cout<<j<<" "<<j/nx<<" "<<j/mx<<endl;
        if(s[j/nx]!=t[j/mx])flag=false;
        j+=x;
    }
    if(flag)cout<<l;else cout<<-1;

    

        
}