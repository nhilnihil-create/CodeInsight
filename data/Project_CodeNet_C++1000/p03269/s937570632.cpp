#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;
 
vector<pair<pi, int> > ed;

signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int l;	cin >> l;
	int n = log2(1.0*l) + 1;
	for(int i = 1; i < n; i++){
		ed.push_back({{i, i+1}, 0});
		ed.push_back({{i, i+1}, pow(2, n-i-1)});
	}	
	int cur = pow(2, n-1);
	l -= cur;
	while(l > 0){
		int x = log2(1.0*l);
		ed.push_back({{1, n-x}, cur});
		l -= pow(2, x);
		cur += pow(2, x);
	}
	cout << n << " " << ed.size() << endl;
	for(auto i: ed)
		cout << i.fi.fi << " " << i.fi.se << " " << i.se << endl;
	return 0;
}