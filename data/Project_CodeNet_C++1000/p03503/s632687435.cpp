#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

const int tage = 10;

int main(){
	int n; cin >> n;
	cin.ignore();
	vector<bitset<tage>> f;
	for( int i = 0; i < n; ++i ){
		string s; getline(cin, s);
		s.erase( remove( s.begin(), s.end(), ' ' ), s.end() );
		f.emplace_back(s);
	}
	int p[n][tage+1];
	for( int i = 0; i < n; ++i ){
		for( int t = 0; t <= tage; ++t ){
			cin >> p[i][t];
		}
	}
	int ans = -inf;
	for( int cond = 1; cond < (1<<10); ++cond ){
		int sum = 0;
		for( int i = 0; i < n; ++i ){
			auto tmp = f[i];
			tmp &= cond;
			sum += p[i][tmp.count()];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}