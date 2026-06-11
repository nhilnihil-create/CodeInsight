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
	int n, m, x, y; cin >> n >> m >> x >> y;
	int mx = x, my = y;
	rep(i,n){
		int a; cin >> a;
		mx = max(mx, a);
	}
	rep(i,m){
		int a; cin >> a;
		my = min(my, a);
	}
	if(mx < my) cout << "No War" << endl;
	else cout << "War" << endl;
} 