/********************/
/* K B G D E L T A */
/*     DA-IICT      */
/********************/
 
#include<bits/stdc++.h>
using namespace std; 
using   ll=long long;
#define fast           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl           "\n"
#define F(i,n)         for(ll i=0;i<n;i++)
#define rep(i,a,b)     for(ll i=a;i<b;i++)
#define repp(i,a,b)    for(ll i=a;i>=b;i--)
#define pb             push_back
#define mp             make_pair
#define vll            vector<ll>
#define f              first
#define s              second
#define pll            pair<ll,ll>
#define ALL(v)         v.begin(),v.end()
#define ALLR(v)        v.rbegin(),v.rend()
#define pii            3.14159265358979323
#define mod            1000000007
 
void solve()
{
    ll n,a,b;

    cin>>n>>a>>b;

    vll p(n);

    F(i,n)
    {
        cin>>p[i];
    }

    sort(ALL(p));

    ll a1=0,a2=0,a3=0;

    for(int i=0;i<n;i++)
    {
        if(p[i]<=a)                 a1++;

        else if(p[i]>a && p[i]<=b)  a2++;

        else                        a3++;
    }

    cout<<min({a1,a2,a3});

}
 
signed main(){
 
    fast;
 
    ll t=1;
 
    while(t--)
    {
        solve();
    }
 
    return 0;
}