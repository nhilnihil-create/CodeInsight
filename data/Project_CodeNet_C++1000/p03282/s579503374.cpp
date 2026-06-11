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
	ll k;
	string s; cin >> s >> k;
	for(int i = 0; i < min(1LL*sz(s),k); ++i){
		if(s[i]!= '1'){
			cout<<s[i];return;
		}
	}
	cout<<1;
}
int main(){
	int t=1;
	//cin >> t;
	while(t--){
		solve();
		cout <<'\n';
	}
}
