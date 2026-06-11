#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> l(m);
	vector<int> r(m);
	rep(i,m) cin >> l[i] >> r[i];
	int mx = 0;
	int mn = 10000000;
	rep(i,m){
		mx = max(l[i],mx);
		mn = min(r[i],mn);
	}
	if(mn - mx < 0) cout << 0 << endl;
	else cout << mn - mx + 1 << endl;
}