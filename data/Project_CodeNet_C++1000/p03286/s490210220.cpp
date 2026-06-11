#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
const ll LINF = ((ll)1<<60);

signed main(){
	//cout << fixed << setprecision(10);
	ll n; cin >> n;
	string ans;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	while(n){
		if(n % 2 != 0){
			ans = '1' + ans;
			--n;
		}
		else ans = '0' + ans;
		n /= -2;
	}
	cout << ans << endl;

	return 0;
}