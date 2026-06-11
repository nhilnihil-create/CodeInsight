#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=1e9+7;
const long double PI = acos(0);
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
int main() {
	int set, set2;
	vector<vector<int>> a(3, vector<int>(3));
	rep(i,3){
		rep(j,3){
			cin >> a[i][j];
		}
	}
	rep(i,3){
		rep(j,3){
			if(j == 0) set = a[i][j];
			a[i][j]-=set;
		}
	}

	/*rep(i,3){
		rep(j,3){
			cout << a[i][j];
		}
		cout << endl;
	}
	*/
	int memo = 0;
	bool ok = true;
	rep(i,3){
		int sum = 0;
		rep(j,3){
			sum+=a[i][j];
		}
		if(i == 0) memo = sum;
		else{
			if(memo != sum) ok = false;
		}
	}
	if(ok) cout << "Yes";
	else cout << "No";
	return 0;
}