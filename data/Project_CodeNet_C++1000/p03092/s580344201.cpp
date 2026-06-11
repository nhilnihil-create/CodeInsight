#include <iostream>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

struct SegTree{
	int size;
	vector<int> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = 0;
	}
	
	void update(int i, int val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = seg[i*2] + seg[i*2+1];
		}
	}

	int query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		int lval = query(a, b, k*2, l, (l+r)/2);
		int rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return lval + rval;
	}
	int query(int a, int b)
	{
		if(a > b) return 0;
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n;
llint a, b;
llint p[5005], pos[5005];
llint dp[5005][5005];
SegTree seg(13);

int main(void)
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		pos[p[i]] = i;
	}
	
	for(int i = 1; i <= n; i++) seg.update(i, 1);
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			if(pos[i+1] <= j) dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
			else{
				dp[i+1][j] = min(dp[i+1][j], dp[i][j] + b);
				dp[i+1][pos[i+1]] = min(dp[i+1][pos[i+1]], dp[i][j] + a*seg.query(j+1, pos[i+1]-1));
			}
		}
		seg.update(pos[i+1], 0);
	}
	
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	
	
	llint ans = inf;
	for(int i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}