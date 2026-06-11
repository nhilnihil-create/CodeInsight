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
ll gcd(ll  a, ll b)
{
    if (a%b == 0)
    {
        return(b);
    }
    else
    {
        return(gcd(b, a%b));
    }
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    godspeed
    ll  i,j,n,m,k;
    string s,t;
    cin >> n >> m;
    cin >> s >> t;
    bool ans=true;

    for(i=0; i<gcd(n,m); i++)
    {
        if(s.at(n*i/gcd(n,m))!=t.at(m*i/gcd(n,m)))
        {
            ans=false;
            break;
        }

    }
    if(ans)
        cout << lcm(n,m) << endl;
    else
        cout << -1 << endl;
    return 0;
}
