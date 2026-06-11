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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h){
		cin >> s[i];
	}
	vector<int>x = {1, -1, 0, 0};
	vector<int>y = {0, 0, 1, -1};
	rep(i,h){
		rep(j,w){
			if(s[i][j] == '#'){
				bool ok = false;
				rep(k,4){
					if(i+y[k]<0 || i+y[k]>=h || j+x[k]<0 || j+x[k]>=w) continue;
					if(s[i+y[k]][j+x[k]] == '#') ok = true;
				}
				if(!ok){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	
	return 0;
}