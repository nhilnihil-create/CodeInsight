#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef vector<int> vi;
const int inf = 1e9+7;
const int INF = 1e18+7;
const int mod = 1e9+7;
//26

int e[100];
int calc(int n){
	int ans = 0;
	while(n > 0){
		ans += n%10;
		n /= 10;
	}
	return ans;
}

signed main(){
	int n, x = 1;
	scanf("%lld", &n);
	e[0] = 1;
	rrep(i,18)e[i] = e[i-1]*10;
	rep(i,n){
		printf("%lld\n", x);
		x++;
		int s = calc(x);
		P p = dmp(x, s);
		for(int j = 0;e[j] <= x;j++){
			int tmp = (x%e[j+1])/e[j];
			x += (9-tmp)*e[j];
			s += (9-tmp);
			if(x*p.se < s*p.fi)p = dmp(x, s);
		}
		x = p.fi;
	}
	return 0;
}



