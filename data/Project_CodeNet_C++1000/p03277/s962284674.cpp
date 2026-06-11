#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define all(c) c.begin(), c.end()
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int N = 1e5 + 5;

struct BIT {
	int t[2*N];
	void edit(int x,int val){
		x+=N;
		for(++x;x<2*N;x+=(x&-x)){
			t[x] += val;
		}
	}
	int query(int x){
		int res = 0;
		x+=N;
		for(++x;x;x &= x - 1){
			res += t[x];
		}
		return res;	
	}
	void clear(){
		memset(t,0,sizeof(t));
	}
} tree;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> v(n);
	ll sub = 1LL * n * (n - 1)/2 + n;
	rep(i,0,n)cin >> v[i];
	int l = 0, r = 1e9+1;	
	int ans = 0;
	while(l <= r){
		tree.clear();
		int m = l + (r-l)/2;
		int rsum = 0;
		tree.edit(0,1);
		ll cnt = 0;
		rep(i,0,n){
			if(v[i] <= m)++rsum;
			else --rsum;
			cnt += tree.query(rsum-1);
			tree.edit(rsum,1);
		}
		if(cnt * 2 > sub){
			ans = m;	
			r = m - 1;
		}
		else{
			l = m + 1;
		}
	}
	cout << ans << '\n';
}
