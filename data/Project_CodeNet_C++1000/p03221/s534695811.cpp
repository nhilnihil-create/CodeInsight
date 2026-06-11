#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
vector<pair<int, int> > g[N];
string ans[N];

string getString(int n){
	string ret = "";
	for(int i = 0; i < 6; i++){
		ret += char(n%10 + '0');
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int p, y;
		cin>>p>>y;
		g[p].push_back({y, i});
	}
	for(int i = 1; i <= n; i++){
		sort(g[i].begin(), g[i].end());
		string s = getString(i);
		for(int j = 0; j < g[i].size(); j++){
			string t = getString(j + 1);
			ans[g[i][j].second] = s + t;
		}
	}
	for(int i = 0; i < m; i++){
		cout<<ans[i]<<'\n';
	}

	return 0;
}