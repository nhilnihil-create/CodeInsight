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
#define INF 1LL << 60
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
int n,a,b;

int main(){
	fast_io();
	cin >> n >> a >> b;
	if(a + b > n + 1 || a > n || b > n){cout << -1 << '\n';return 0;}
	vector<int> res;
	res.pb(b);
	int left = n - b - (a - 1);
	if(left < 0){cout << -1 << '\n';return 0;}
	cu(i,1,a){
		int c = 1;
		if(left){
			c+=min(left,b-1);	
			left-=min(left,b-1);
		}
		res.pb(c);
	}
	vector<int> ans;
	int cmax = 0;
	cu(i,0,res.size()){
		cmax+=res[i];
		fd(j,cmax,cmax-res[i]+1)ans.pb(j);
	}
	if(ans.size() == n){
		for(int a:ans){
			cout << a << ' ';
		}
		cout << '\n';
	}
	else {cout << -1 << '\n';return 0;}
}

