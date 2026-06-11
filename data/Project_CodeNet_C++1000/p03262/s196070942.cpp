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
	int n, x,g; cin>> n >> x;
	vi a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(i == 0)
			g = abs(x-a[i]);
		else
			g = __gcd(g,abs(x-a[i]));
	}
	cout << g;
}
int main(){
	int t=1;
	//cin >> t;
	while(t--){
		solve();
		cout <<'\n';
	}
}
