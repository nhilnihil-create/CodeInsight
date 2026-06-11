#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace _gnu_pbds;
#define vb __int128
#define ll long long
#define ld long double
#define full(a) a.begin(),a.end()
#define fr(i,a,b) for(ll i = a ; i < b ; i++)
#define stoink stack<ll>
#define quu queue<ll>
#define quee queue<pair<ll,ll>>
#define vec vector <ll>
#define vecd vector<ld>
#define vg vector<vector<ll> >
#define eg vector<pair<ll,ll>>
#define vgw vector<vector<pair<ll,ll> > >
#define pa pair<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define pre 0.00000000000000000001
#define inf 100000000
#define mod 998244353
#define endl '\n'
vec ft(200005);
ll n;
void add(ll ind,ll val) {
    while(ind <= n){
        ft[ind] =max(val,ft[ind]);
        ind += ind & -ind;
    }
}
ll sum(ll ind) {
    ll maxi = 0;
    while(ind > 0) {
        maxi = max(ft[ind],maxi);
        ind -= ind & -ind;
    }
    return maxi;
}
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    vec height(n);
    vec beauty(n);
    fr(i,0,n) cin >> height[i];
    fr(i,0,n) cin >> beauty[i];
    ll ans = 0;
    fr(i,0,n) {
        ll val = beauty[i] + sum(height[i]);
        ans = max(ans,val);
        add(height[i],val);
    }
    cout << ans << endl;
	return 0;
}	