#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	int n, k;
	cin >> n >> k;
	ll ans = -1e12;
	deque<int> v;
	rep(i,n) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int r = min(n, k);
	for(int i = 0; i <= r; i++){
		for(int j = 0; i+j<=r; j++){
			deque<int> nv = v;
			priority_queue<int, vector<int>, greater<int>> c;
			rep(a,i) {
				c.push(nv.front());
				nv.pop_front();
			}
			rep(b,j) {
				c.push(nv.back());
				nv.pop_back();
			}
			ll cost = 0;
			rep(a,max(0,k-(i+j))){
				if(c.size()&&c.top()<0) c.pop();
			}
			while(c.size()){
				cost += c.top();
				c.pop();
			}
			chmax(ans, cost);
		} 
	}
	cout << ans << endl;
}