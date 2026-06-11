//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep(i,n)    for(ll i=0; i<n; i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    ll i,j,n,m,a,b,c;
    string x;
    map<string,ll>s,t;
    cin>>n;
    rep(i,n)
    {
        cin>>x;
        s[x]++;
    }
    cin>>m;
       rep(i,m)
    {
        cin>>x;
        t[x]++;
    }
    ll ans=0,tmp;
    for(auto e:s)
    {
        tmp=e.se-t[e.fi];
        ans=max(ans,tmp);
    }
        cout<<ans<<endl;
    return 0;
}



