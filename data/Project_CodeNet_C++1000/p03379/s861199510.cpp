//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep(i,n)    for(ll i=1; i<=n; i++)
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
    ll i,j,n,x;
    cin>>n;
    vector<ll>a(n),b(n);
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    b=a;
    sort(a.begin(),a.end());
    ll medo=a[n/2-1],mede=a[n/2];
    for(i=0; i<n; i++)
    {
        if(b[i]<=medo)
        {
            cout<<mede<<endl;
            continue;
        }
        if(b[i]>=mede)
            cout<<medo<<endl;

    }

    return 0;
}



