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
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    godspeed
    ll  i,j,k,l,n,ans=0;
    string s;
    cin>>n;
    ll a[n+1];
    a[0]=2;
    a[1]=1;
    for(i=2;i<n+1;i++)
    {
        a[i]=a[i-2]+a[i-1];
     //   cout<<a[i]<<endl;
    }

    cout<<a[n]<<endl;
    return 0;
}



