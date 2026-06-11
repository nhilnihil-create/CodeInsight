#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

const int mxN = 1009;
ll a[mxN][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll mx = -1e18;

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	for(int bit = 0; bit < (1 << 3); bit++) {
		vector<ll> tot(n);
		for(int i = 0; i < 3; i++) {
			if(1&bit>>i) {
				for(int j = 0; j < n; j++) {
					tot[j] += a[j][i];
				}
			} else {
				for(int j = 0; j < n; j++) {
					tot[j] -= a[j][i];
				}
			}
		}
		sort(tot.rbegin(), tot.rend());
		ll now = 0;
		for(int i = 0; i < m; i++) {
			now += tot[i];
		}
		chmax(mx, now);
	}
	cout << mx << endl;
}