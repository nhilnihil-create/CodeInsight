#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;

const int Mx=1e6+11;
const double PI = acos(-1);
#define MOD 1000000007

#define nl '\n'
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair

#define sz(x) x.size()
#define tt int t; cin>>t; while(t--)
#define be(a) (a).begin(),(a).end()
#define rbe(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a,b,sizeof(a))
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define frac cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

void solve()
{
    ll n;
    vector< pll> ev,od;
    map<ll,ll>m;

    cin>>n;

    ll a[n];///main array
    for(ll i=0; i<n; i++)
        cin>>a[i];

    for(ll i=0; i<n; i+=2) ///even index access
        m[a[i]]++;
    for(auto i:m)
    {
        ev.pb({i.S,i.F});///storing frequencies with their numbers
    }

    m.clear();

    for(ll i=1; i<n; i+=2) ///odd indexes access
        m[a[i]]++;
    for(auto i:m)
    {
        od.pb({i.S,i.F});///storing frequencies with their numbers
    }

    sort(rbe(ev));
    sort(rbe(od));

    if(ev[0].S!=od[0].S)///sequentially not both max numbers are same
    {
            cout<<n-(ev[0].F+od[0].F)<<nl;
    }
    else///sequentially both max numbers are same
    {
        ll s1=INT_MAX,s2=INT_MAX;
        
        if(sz(ev)>1)///if 2nd max available on even vector
        {
                s1=n-(ev[1].F+od[0].F);
        }
        
        if(sz(od)>1)///if 2nd max available on odd vector
        {
                s2=n-(ev[0].F+od[1].F);
        }
        
        s1=min(s1,s2);///dutor moddhe min niye
        
        s2=min((n-ev[0].F),(n-od[0].F));///if no 2nd max then taking all even pos or all odd pos and finding the min of them
        
        s1=min(s1,s2);
        
        cout<<s1<<nl;
    }
}

int main()
{
    fio;
    solve();
    return 0;
}
