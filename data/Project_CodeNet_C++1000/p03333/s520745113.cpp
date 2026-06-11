#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define item pair<pii,int>

const int N = 1e5 + 7;

int n;
vector<item> l, r;

bool used[N];

bool cmp(item a, item b){
	return (a.fi.se < b.fi.se || (a.fi.se == b.fi.se && a.fi.fi < b.fi.fi));
}

signed main(){
	cin >> n;
	for(int i = 0; i < n; ++i){
		int L, R;
		cin >> L >> R;
		l.push_back({{L, R}, i});
	}
	l.push_back({{0, 0}, n});
	r = l;
	n = l.size();
	sort(begin(l), end(l));
	sort(begin(r), end(r), cmp);
	int ans = 0;
	
	for(int p1 = n - 1, p2 = 0, sl = 0, sr = 0; ; ){
		while(p1 >= 0 && used[l[p1].se]) --p1;
		if(p1 < 0) break;
		used[l[p1].se] = true;
		sl += l[p1].fi.fi;
		--p1;
		
		while(p2 < n && used[r[p2].se]) ++p2;
		if(p2 == n) break;
		used[r[p2].se] = true;
		sr += r[p2].fi.se;
		++p2;
		ans = max(ans, 2 * (sl - sr));
	}
	cout << ans;
}
