#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	string a, b, c;
	cin >> n >> a >> b >> c;
	int ans = 0;
	rep(i, n){
		map<char, int> m;
		int ma = 0;
		m[a.at(i)]++;
		if(m[a.at(i)] > ma) ma = m[a.at(i)];
		m[b.at(i)]++;
		if(m[b.at(i)] > ma) ma = m[b.at(i)];
		m[c.at(i)]++;
		if(m[c.at(i)] > ma) ma = m[c.at(i)];
		ans += 3 - ma;
	}
	cout << ans << endl;
	return 0;
}