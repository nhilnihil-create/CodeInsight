#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
int main() {
	string s;
	cin >> s;
	vector<int> a(4);
	rep(i,4) a[i] = s[i]-'0';

	for(int bit = 0; bit<(1<<3); bit++){
		string t = to_string(a[0]);
		int sum = a[0];
		for(int i = 0; i<3; i++){
			if(bit&(1<<i)){
				sum+=a[i+1];
				t+=("+" + to_string(a[i+1]));
			}else{
				sum-=a[i+1];
				t+=("-" + to_string(a[i+1]));
			}
		}

		if(sum == 7){
			cout << t << "=7" <<endl;
			return 0;
		}
	}


	return 0;
}
