#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define uint unsigned int
#define MOD 1000000007
#define MAXN 200005
#define MAXH 4
#define MAXM 100
#define INF 1LL << 30
#define ll long long
#define ull unsigned long long
#define RNG mt19937
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;
const int N = 18;
int dp[1 << N][N],c[1 << N];

int main(){
	fast_io();
	int ans = 0;
	int n;cin >> n;
	int x;cin >> x;
	cu(i,0,1 << n)c[i] = x;

	cu(i,1,1 << n){
		cin >> x;	
		c[i] = x;
		cu(j,0,n)dp[i][j] = x;

		cu(j,0,n){
			if((i >> j) & 1){
				cu(k,0,n){
					if(j != k && ((i >> k) & 1)){
						gmax(dp[i][j], dp[i ^ (1 << k)][j]); 
					}
				}
				gmax(c[i], c[i ^ (1 << j)]);
			}
		}

		cu(j,0,n){
			if((i >> j) & 1){
				gmax(ans, dp[i][j] + c[i ^ (1 << j)]);
			}
		}

		cout << ans << '\n';
	}
}
