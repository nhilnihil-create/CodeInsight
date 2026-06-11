//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define limit 1000000000000000000 //1e18
#define mod 1000000007 //1e9+7
#define llu long long unsigned
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,n)    for(ll i=0; i<n; i++)
#define rep1(i,a,b)    for(ll i=a; i<b; i++)
#define repV(i,n)    for(ll i=0; i<v.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  i,j,n,m,k;
    string s,t;
    cin >> n >> m;
    if(n%m==0)
     return   cout << -1 << endl,0;
for(i=1;;i++)
{
    if((i*n)%m!=0)
       return cout << i*n << endl,0;

}
    return 0;
}
