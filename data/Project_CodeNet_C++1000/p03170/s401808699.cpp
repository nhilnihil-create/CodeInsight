#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
#define INF (ll) (1e9)
#define mod (ll) (1e9 + 7)
#define endl "\n"
#define tt ll testcase; cin>>testcase; while(testcase--)
 
const int mxn = 1*(1e5) + 5;
ll n, m;
 
void solve(){
	cin >> n >> m;
	ll a[n];
	bool v[m+1] = {};
	for(int i=0; i<n; i++) {
		cin >> a[i];
		v[a[i]] = 1;
	}
	for(int i=0; i<=m; i++) {
		bool win = true;
		for(int j=n-1; j>=0; j--) {
			if((!v[i-a[j]]) && (i-a[j] >= 0)) {
				win = false;
				break;
			}
		}
		if(!win) {
			v[i] = 1;
		}
	}
	// for(int i=0; i<=m; i++) {
	// 	cout << v[i];
	// }
	if(v[m]) {
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
}

int main(){
	fast;
	#ifndef ONLINE_JUDGE 
   freopen("input.txt", "r", stdin); 
   freopen("output.txt", "w", stdout); 
   #endif 
   
	// tt
		solve();
	return 0;
}