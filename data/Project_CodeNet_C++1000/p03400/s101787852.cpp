//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep(i,n)    for(ll i=0; i<n; i++)
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    godspeed
    ll i,j,x,n,d,ans;
    cin>>n>>d>>x;
    ans=x+n;
    ll a[n];
    rep(i,n)
    cin>>a[i];
    rep(i,n)
    {
        ll cnt=1,choc=0;
        while((a[i]*cnt)+1<=d){
            choc++;cnt++;
        }
        ans+=choc;
    }


    cout<<ans<<endl;
    return 0;
}



