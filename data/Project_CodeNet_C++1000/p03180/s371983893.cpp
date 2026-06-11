#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 340
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll mod=1000000007;
const ll inf=1e18;
const ld pai=acos(-1);
ll n;
ll a[19][19];
ll dp[(1<<16)+9];
ll cost[(1<<16)+9];
ll calc(ll mask){
	ll sum=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if((mask&(1<<i)) && (mask&(1<<j))){
				sum+=a[i][j];
			}
		}
	}
	return sum;
}
int main(){
	cin>>n;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(ll i=0;i<(1<<n);i++)cost[i]=calc(i);
	for(ll i=1;i<(1<<n);i++){
		for(ll j=i;j;j=(j-1)&i){
			dp[i]=max(dp[i],dp[i^j]+cost[j]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}
