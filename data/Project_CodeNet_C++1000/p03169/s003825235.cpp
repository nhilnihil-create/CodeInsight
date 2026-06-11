#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define vv vector
#define pp pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define fastio                    \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
typedef pair<ll, ll> pll;
typedef vv<ll> vll;
typedef vv<pll> vpll;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//adds two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set]
//(2)set.order_of_key(k)[count of elements strictly less than k]
#define LG(args...)                               \
	{                                             \
		string _s = #args;                        \
		replace(_s.begin(), _s.end(), ',', ' ');  \
		stringstream _ss(_s);                     \
		err(istream_iterator<string>(_ss), args); \
		cerr << endl;                             \
	}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "(" << *it << ":" << a << ") ";
	err(++it, args...);
}
//:::::::::::::::::::::::::::::::::::::::::::::
const ll INF = 9e18;
const ll MOD = 1e9 + 7;
// #define dbg
#define ld long double

const ll maxn = 303;
ld dp[maxn][maxn][maxn];

int main(){
	fastio;
	ll n;
	cin>>n;
	vll a(n);
	ll c1=0,c2=0,c3=0;
	for(auto& i: a){
		cin>>i;
		if(i==1)
			c1++;
		else if(i==2)
			c2++;
		else
			c3++;
	}

	for(ll k=0; k<=maxn; k++){
		for(ll j=0; j<=maxn; j++){
			for(ll i=0; i<=maxn; i++){

				if(i+j+k > n)
					continue;
				if(i+j+k == 0){
					dp[i][j][k]=0;
					continue;
				}

				dp[i][j][k] = (n+0.0)/(i+j+k);
				auto p =[&](ld o){
					return o/(i+j+k);
				};
				if(i)
					dp[i][j][k] += p(i)*dp[i-1][j][k];
				if(j)
					dp[i][j][k] += p(j)*dp[i+1][j-1][k];
				if(k)
					dp[i][j][k] += p(k)*dp[i][j+1][k-1];
			}
		}
	}

	// for(ll i=0; i<=n; i++){
	// 	for(ll j=0; j<=n; j++){
	// 		for(ll k=0; k<=n; k++){
	// 			LG(i,j,k, dp[i][j][k])
	// 		}
	// 	}
	// }
	cout.precision(10);
	cout<<dp[c1][c2][c3];

}