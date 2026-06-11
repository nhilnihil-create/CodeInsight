//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  t,i,x,j,k,a,b,c,ans=0;
    cin>>a>>b>>c;
    if(a+b>=c)
    {
        ans=b+c;
    }
    else
    {

        ans=2*min(b,c);
        c=max(0LL,c-b);
   // cout<<ans<<" "<<c<<endl;
        ans+=min(c,a);
   // cout<<ans<<endl;
        c-=min(c,a);
   // cout<<ans<<" "<<c<<endl;
        if(c>0) ans++;
    }

    cout<<ans<<endl;

    return 0;
}



