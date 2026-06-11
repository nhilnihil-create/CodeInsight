#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int dx[] = { -1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1 };
const int dy[] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1 };
#define NN 8010000
#define TC int t;cin>>t;for(int T=1;T<=t;T++)
#define mod 1000000007
#define PI acos(-1)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mem(a,n) memset(a,n,sizeof(a))
void AIA() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
//cout<<fixed<<setprecision(20);
// freopen("stand.in","r",stdin);
// freopen("stand.out","w",stdout);
bool isprime(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)return 0;
	}
	return (n!=1);
}
ll gcd(ll x, ll y)
{
	return (y == 0 ? x : gcd(y, x % y));
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll rem(int x, int N){
	return (x % N + N) % N;
}
int n,m;
ll dp[1007][1007];
char arr[1007][1007];

int main()
{
	//cout<<fixed<<setprecision(6);
	AIA();
	int n,m;
	cin>>n>>m;
	dp[0][0] = 1;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[i][j];
	for(int i = 0;i<n;i++)for(int j=0;j<m;j++){
		if(arr[i][j] == '#')continue;
		if(i == 0 && j == 0)continue;
		if(i == 0)dp[i][j] = dp[i][j - 1];
		else if(j == 0)dp[i][j] = dp[i-1][j];
		else dp[i][j] = ((dp[i][j] % mod) + (dp[i - 1][j] % mod) + (dp[i][j - 1] % mod)) % mod;
	}	
	cout << dp[n-1][m-1];
	return 0;
}