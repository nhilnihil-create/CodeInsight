#include "bits/stdc++.h"
using namespace std;
#define fi first
#define se second
#define ll long long
#define dbg(v) cerr<<#v<<" = "<<v<<'\n'
#define vi vector<int>
#define vl vector <ll>
#define pii pair<int,int>
#define mp make_pair
#define db long double
#define pb push_back
#define all(s) s.begin(),s.end()
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
int main(void)
{
    int q;
    cin>>q;
    while (q --) {
    	ll a,b;
    	cin>>a>>b;
    	ll n = a * b;
    	if (a > b)
    		swap(a,b);
    	ll sq = 0;
    	for (ll k = 1ll << 30;k;k /= 2)
    		if ((n - 1) / (sq + k) / (sq + k) >= 1)
    			sq += k;
    	ll ans;
    	if (a >= b - 1)
    		ans = 2 * (a - 1);
    	else
    	if (sq * (sq + 1) >= n)
    		ans = 2 * sq - 2;
    	else
    		ans = 2 * sq - 1;
    	cout << ans << '\n';
    }
    return 0;
}