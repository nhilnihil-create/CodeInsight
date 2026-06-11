#include<bits/stdc++.h>
using namespace std;
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
    ll t,i,j,n,m,l,r,s=0;
    cin>>n>>m;
    vector<int>v1,v2;
    for(i=0;i<m;i++)
    {
        cin>>l>>r;
        v1.pb(l);
        v2.pb(r);
    }
    sort(v1.B,v1.E);
    sort(v2.B,v2.E);
    for(i=1;i<=n;i++)
    {
        l=upper_bound(v1.B,v1.E,i)-v1.B;
        r=lower_bound(v2.B,v2.E,i)-v2.B;
        if((l-r)==m)
        {
            s++;
        }
    }
    cout<<s<<"\n";
    return 0;
}