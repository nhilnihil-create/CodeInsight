#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define ar array

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int > pii;
const ll MOD =1e9+7;


void solve(){
	int n; cin >> n;
	ll s=0;
	for(int i = 0; i < n; ++i){
		int x; cin >> x;
		s += (x-1);
	}
	cout << s;
}

int main(){
	int t=1;
	//cin >> t;
	while(t--){
		solve();
		cout <<'\n';
	}
}
