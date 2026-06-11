#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9 + 10;
const ll INFLL = 3e18;

ll bs(vector<int>& v, int x, bool hi){
	
	int l = 0;
	int r = v.size() - 1;
	int ans = 0;
	
	while(l <= r){
		
		int mid = (l + r)/2;
		if(hi){ // procurando maior
			if(v[mid] <= x){
				l = mid + 1;
			} else {
				r = mid - 1;
				ans = v.size() - mid;
			}
		} else { // procurando menores
			if(v[mid] >= x){
				r = mid - 1;
			} else {
				l = mid + 1;
				ans = mid + 1;
			}
		}
	}
	
	return ans;
}

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> a(n), b(n), c(n);
	
	for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	
	for(int i = 0 ; i < n ; i ++)
		cin >> b[i];
	
	for(int i = 0 ; i < n ; i ++)
		cin >> c[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	
	ll ans = 0;
	
	for(int i = 0 ; i < n ; i ++){
		
		ll smalla = bs(a, b[i], 0);
		ll smallb = bs(c, b[i], 1);
		ans += smalla*smallb;
	}
	
	cout << ans << "\n";
	
	return 0;
}