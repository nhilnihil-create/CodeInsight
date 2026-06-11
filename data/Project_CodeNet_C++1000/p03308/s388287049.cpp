#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define F first
#define S second
using namespace std;

typedef vector <ll> vl;
typedef pair< ll, ll > pll;


int main()
{
    ll t,i,j,k,ans,n;

    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        vl v(n);
        rep(p, 0, n)cin>>v[p];

        cout<<(*max_element(all(v)))-(*min_element(all(v)));
    }
    
    return 0;
}
