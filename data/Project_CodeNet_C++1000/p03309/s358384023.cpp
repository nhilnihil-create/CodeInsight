#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ld long double
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define mp map<ll, ll>
#define um unordered_map<ll, ll>
#define st set<ll> 
#define us unordered_set<ll>
#define vt vector<ll>
#define pll pair<ll, ll>
#define fl(i, x, y) for(ll i=x;i<y;++i)
#define flr(i, x, y) for(ll i=x;i>=y;--i)

int main()
{
    ll n;
    cin>>n;
    ll a[n], mn=LLONG_MAX, s=0, s1=0, b[n];
    fl(i, 0, n)
    {
        cin>>a[i];
        a[i]-=(i+1);
        b[i]=a[i];
    }
    sort(b, b+n);
    mn = b[n/2];
    fl(i, 0, n)
    {
        s+=(abs(a[i]-mn));
    }
    fl(i, 0, n)
    {
        s1+=(abs(a[i]+mn));
    }
    cout<<min(s, s1)<<endl;
	return 0;
}