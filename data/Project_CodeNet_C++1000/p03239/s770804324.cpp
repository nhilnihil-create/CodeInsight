#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
using graph = vector<vector<int>>;

const double pi = 3.14159265358979323846;
const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n, T; cin >> n >> T;
	int ans = 10000; int tmp = T;
	rep(i,n){
		int c, t; cin >> c >> t;
		if(T >= t){
			ans = min(ans, c);
		}
	}
	if(ans == 10000) cout << "TLE" << endl;
	else cout << ans << endl;
} 