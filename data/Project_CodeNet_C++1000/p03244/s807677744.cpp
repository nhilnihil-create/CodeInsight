#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define ar array
#define forn(i, n) for(int i = 0; i < n ; ++i)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int > pii;
typedef vector<pii> vpi;
const ll MOD =1e9+7;

void solve(){
	int n; cin >> n;
	vi a(n); forn(i, n) cin >> a[i];
	map<int,int> mp1 , mp2;
	int ans=n;
	for(int i=0, j = 1; i < n-1 && j < n; i+=2, j+=2){
		mp1[a[i]]++;
		mp2[a[j]]++;
	}
	set<ar<int,2>> s, t;
	for(auto x: mp1)
		s.insert({x.se,x.fi});
	for(auto x: mp2)
		t.insert({x.se,x.fi});
	
	int od = (*s.rbegin())[1],od1=0,ev1=0;
	if(sz(s)>1)
		od1 = (*++s.rbegin())[1];
	int ev = (*t.rbegin())[1];
	if(sz(t) > 1)
		ev1 = (*++t.rbegin())[1];
	if(od != ev){
		ans = n - mp1[od]-mp2[ev];
		cout<<ans;return;
	}
	if(od == ev && sz(s) < 2 && sz(t) < 2){
		cout << n/2;return;
	}
	ans = min(n - mp1[od]-mp2[ev1], n-mp1[od1]-mp2[ev]);
	cout << ans;
}
int main(){
	int t=1;
	//cin >> t;
	while(t--){
		solve();
		cout <<'\n';
	}
}
