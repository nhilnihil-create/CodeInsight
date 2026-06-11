#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main()
{
   int n,k;
   cin >> n >> k;
   vector<vector<int>> ds(n);
	rep(i,n){
		int t,d;
		cin >> t >> d;
		--t;
		ds[t].push_back(d);
	}
	vector<int> y1,y0;
	rep(i,n){
		if (ds[i].size() == 0) continue;
		sort(ds[i].begin(), ds[i].end());
		y1.push_back(ds[i].back());
		ds[i].pop_back();
		y0.insert(y0.end(),ds[i].begin(),ds[i].end());
	}
	sort(y1.rbegin(),y1.rend());
	sort(y0.rbegin(),y0.rend());
	int Y = max(1, k - int(y0.size()));
	ll ans = 0;
	ll X = 0;
	rep(i,Y)X+=y1[i];
	rep(i,k-Y)X+=y0[i];
	ans = max(ans,X+(ll)Y*Y);
	while(1){
		++Y;
		if(Y>k || Y > y1.size())break;
		X = 0;
		rep(i,Y)X+=y1[i];
		rep(i,k-Y)X+=y0[i];
		ans = max(ans,X+(ll)Y*Y);
	}
	cout << ans << endl;
	return 0;
}