#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define fi first
#define se second

int n,a[100005],d[100005],ans = LLONG_MAX;
int ra(int l,int r){
	return d[r] - d[l - 1];
}
int f(int l,int r){
	int res = l;
	int L = l, R = r;
	while(L <= R){
		int M = (L + R) >> 1;
		if(ra(l, M) * 2 <= ra(l, r)){
			res = M;
			L = M + 1;
		}
		else R = M - 1;
	}
	return res;
}
void c(int l,int m,int r){
	if(l >= m || m >= r || r >= n) return;
	vector<int> prep;
	prep.push_back(ra(1, l));
	prep.push_back(ra(l + 1, m));
	prep.push_back(ra(m + 1, r));
	prep.push_back(ra(r + 1, n));
	ans = min(ans, *max_element(prep.begin(),prep.end()) - *min_element(prep.begin(),prep.end()));
}
signed main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> d[i];
		d[i] += d[i - 1];
		//cout << d[i] << endl;
	}
	for(int i = 2; i <= n - 2 ; i ++){
		int l = f(1, i);
		int r = f(i + 1, n);
		//cout << i << " " << l << " " << r << endl;
		c(l, i, r);
		c(l + 1, i, r);
		c(l, i, r + 1);
		c(l + 1, i, r + 1);
	}
	cout << ans;
}
