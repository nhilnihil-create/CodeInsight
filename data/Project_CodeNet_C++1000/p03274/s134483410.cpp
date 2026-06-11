// oh, the less I know the better
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz
#include <bits/stdc++.h>
#define endl '\n'
#define fst first
#define snd second
#define pb push_back
#define sz(x) int(x.size())
#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){

	fastio;
	int n,k;
	cin >> n >> k;
	vector<int> v1,v2;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x < 0) v1.pb(-x);
		else v2.pb(x);
	}

	sort(v1.begin(),v1.end());

	int ans = 1e9;
	for(int i = 0; i <= sz(v1); ++i){
		int j = k - i;
		if(j-1 >= sz(v2)) continue;
		int d1 = 0, d2 = 0;
		if(i-1 >= 0) d1 = v1[i-1];
		if(j-1 >= 0) d2 = v2[j-1];
		ans = min(ans, d1 + d2 + min(d1,d2));
	}

	cout << ans << endl;

	return 0;
}
