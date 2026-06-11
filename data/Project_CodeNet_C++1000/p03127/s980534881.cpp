#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pi;
priority_queue<pi, vector<pi>, greater<pi> > pq; //min heap

ll mini(ll a,ll b){	return a<b?a:b;}
ll maxi(ll a,ll b){	return a>b?a:b;}
ll gcd(ll a,ll b){	if(b == 0)	return a;return gcd(b,a%b);}
ll binpow(ll n,ll x){	ll ans = 1;while(x){if(x & 1)	ans *= n;n *= n;x >>= 1;}return ans;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<ll> A(n,0);

    for(int i=0;i<n;++i)    cin>>A[i];

    ll ans = A[0];

    for(int i=1;i<n;++i)    ans = gcd(ans, A[i]);

    cout<<ans<<'\n';

    return 0;
}