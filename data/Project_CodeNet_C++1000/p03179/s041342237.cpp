#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<ld> vld;

#define fi first
#define se second

typedef tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const ll inf = ll(1e18);
const int MOD = (1e9 + 7);

int dp[3001][3001],sum1[3001][3001];

void add(int & a,int b){
	a+=b;
	while(a>=MOD) a-=MOD;
}

int mul(int a, int b){
	return (1LL*a*b)%MOD;
}

int su(int i,int l,int r){
	l=max(l,0);
	if(l>r) return 0;
	if(l==0)
		return sum1[i][r]%MOD;
	else{
		return (sum1[i][r]+MOD-sum1[i][l-1])%MOD;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	#ifdef DEBUG_
		freopen("input.txt","r",stdin);
	#endif
	cout.setf(ios::fixed), cout.precision(20);
	ll n;
	cin >> n;
	string st;
	cin >> st;
	for(int i=0;i<3001;i++){
		for(int j=0;j<3001;j++){
			dp[i][j]=0;
			sum1[i][j]=0;
		}
	}
	dp[0][0]=1;
	sum1[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(st[i-1]=='<'){
				dp[i][j]=su(i-1,0,j-1);
			}
			else{
				dp[i][j]=su(i-1,j,i-1);
			}
		}
		sum1[i][0]=dp[i][0];
		for(int j=1;j<=i;j++){
			sum1[i][j]=dp[i][j];
			add(sum1[i][j],sum1[i][j-1]);
		}
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	int ans=0;
	for(int i=0;i<n;i++){
		add(ans,dp[n-1][i]);
	}
	cout<<ans<<"\n";
	return 0;
}

