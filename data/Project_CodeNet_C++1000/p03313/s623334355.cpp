#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

int n, a[1 << 18], maxi;
iiii ans[1 << 18];

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < (1 << n); i++) cin >> a[i];
	for(int i = 0; i < (1 << n); i++){
		ans[i] = {{a[i], i}, {0, -1}};
		for(int j = 0; j < n; j++){
			if(!(i & (1 << j))) continue;
			if(ans[i - (1 << j)].fi.fi > ans[i].fi.fi){
				ans[i].se = ans[i].fi;
				ans[i].fi = ans[i - (1 << j)].fi;
			}
			else if(ans[i - (1 << j)].fi.fi > ans[i].se.fi && (ans[i - (1 << j)].fi != ans[i].fi)) ans[i].se = ans[i - (1 << j)].fi;
			if(ans[i - (1 << j)].se.fi > ans[i].se.fi) ans[i].se = ans[i - (1 << j)].se;
		}
		if(i){
			maxi = max(maxi, ans[i].fi.fi + ans[i].se.fi);
			cout << maxi << "\n";
		}
	}
}
