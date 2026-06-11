#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
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
typedef pair<P, int> Pi;
typedef vector<int> vi;
typedef deque<int> dq;
const int inf = 1e9+7;
const int INF = 1e18+7;

class BIT{
public:
	int n = 1;
	vector<int> bit;
	void init(int N){	//[1, N]のBIT作成
		while(n < N+1)n *= 2;
		bit.resize(n+1);
		fill(all(bit), 0);
	}
	void add(int i, int x){
		while(i <= n){bit[i] += x;i += i&-i;}
	}
	int get(int i){
		int s = 0;
		while(i > 0){s += bit[i];i -= i&-i;}
		return s;
	}
	int lower_bound(int k, int ret = -1){	//ret=見つからなかったときに返すidx
		int lb = 0, ub = n+1;
		while(ub-lb > 1){
			if(get((lb+ub)/2) >= k)ub = (lb+ub)/2;
			else lb = (lb+ub)/2;
		}
		return ub == n+1 ? ret : ub;
	}
};

int a[200000], b[200000];
int n;
BIT bit;
int solve(int mid){
	bit.init(2*n+1);
	int sum = n+1, ans = 0;
	rep(i,n){
		ans += bit.get(sum);
		if(a[i] >= mid)sum++;
		else sum--;
		bit.add(sum, 1);
	}
	return ans;
}

signed main(){
	scanf("%lld", &n);
	rep(i,n)scanf("%lld", &a[i]);
	rep(i,n)b[i] = a[i];
	sort(b, b+n);
	
	int lb = 0, ub = n;
	while(ub-lb > 1){
		int mid = (ub+lb)/2;
		if(solve(b[mid]) >= n*(n+1)/2/2)lb = mid;
		else ub = mid;
	}
	//printf("%lld\n", lb);
	printf("%lld\n", b[lb]);
	return 0;
}




