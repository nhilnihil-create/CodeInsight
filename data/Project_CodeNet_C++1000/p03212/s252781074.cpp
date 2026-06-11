#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Rep(n) for (ll _ = 0; _ < (ll)(n); _++)
#define fs first
#define sc second

template<class S>S sum(vector<S>&a){return accumulate(all(a),S());}
template<class S>S max(vector<S>&a){return *max_element(all(a));}
template<class S>S min(vector<S>&a){return *min_element(all(a));}
ll max(int a,ll b){return max((ll)a,b);} ll max(ll a,int b){return max(a,(ll)b);}
ll min(int a,ll b){return min((ll)a,b);} ll min(ll a,int b){return min(a,(ll)b);}
template <class S> void print(vector<S> &v){for(ll i=0; i<(ll)v.size(); i++){cerr << v[i] << ' ';}cerr << endl;}
template <class S> void print(vector<vector<S>> &v) {for (ll i = 0; i < (ll)v.size(); i++) {for (ll j = 0; j < (ll)v[i].size(); j++) {cerr << v[i][j] << ' ';}cerr << endl;}}

bool is753(int n){
	bool a3 = false;
	bool a5 = false;
	bool a7 = false;
	while(n){
		int a = n % 10;
		if(a == 3) a3 = true;
		else if(a == 5) a5 = true;
		else if(a == 7) a7 = true;
		else return false;
		n /= 10;
	}
	if(a3 && a5 && a7) return true;
	return false;
}

int main(){
	int n; cin >> n;
	int ans = 0;
	if(n < 500000000){
		for(int i=1; i<=n; i++){
			ans += is753(i);
		}
	}else{
		ans += 14384;
		for(int i=500000000; i<=n; i++){
			ans += is753(i);
		}
	}
	cout << ans << endl;
}