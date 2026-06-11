#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define int long long int
#define F first
#define S second
#define pb push_back
#define M 1000000007
#define inf 1e18
#define endl "\n"
#define jam(x) cout<<"Case #"<<x<<": "
#define N 100005

void display1D( vector<int> &v ) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

std::vector<int> v[N];
std::vector<int> ind;

int lp(int n) {
	set<int> st;
	std::vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (ind[i] == 0) st.insert(i);
	}



	while ( !st.empty() ) {
		int cur = *st.begin();
		st.erase(st.begin());
		for ( int adj : v[cur] ) {
			dp[adj] = max(dp[adj], dp[cur] + 1 );
			ind[adj]--;
			if ( ind[adj] == 0 ) st.insert(adj);
		}
	}

	//display1D(dp);
	return *max_element( dp.begin(), dp.end() );
}


int32_t main() {
	fastio;
#ifndef ONLINE_JUDGE
	fileIO;
#endif

	int n, m, a, b;
	cin >> n >> m;
	ind.resize(N);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}

	cout << lp(n);

	return 0;
}