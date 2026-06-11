#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int n;
vector<int> a;
int ans;

void dfs(int d, vector<int> &v){
	if(d == n){
		ll x = 1;
		rep(i, n){
			x *= (a[i] + v[i] - 1);
		}

		if(x % 2 == 0) ans++;
		return;
	}

	for(int i = 0; i < 3; i++){
		v.push_back(i);
		dfs(d+1, v);
		v.pop_back();
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	ans = 0;

	a.resize(n);
	rep(i, n) cin >> a[i];
	
	vector<int> v;
	dfs(0, v);
	cout << ans << endl;
}
