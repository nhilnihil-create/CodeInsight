#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

vector<int> to[100010];
int main()
{
	ll n;
	cin >> n;
	vector<ll> c(n);
	rep(i,n-1){
		int x, y;
		cin >> x >> y;
		--x, --y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	rep(i,n) cin >> c[i];

	sort(c.rbegin(),c.rend());
	int ans = 0;
	rep(i,n){
		if(i==0) continue;
		ans += c[i];
	}

	// BFS
	vector<bool> check(n,false);
	queue<int> que;
	que.push(0);
	int count = 0;
	check[0] = true;
	vector<int> write(n);
	while(!que.empty()){
		int now = que.front(); que.pop();
		write[now] = c[count];
		count ++;

		for(auto x:to[now]){
			if(check[x]) continue;
			que.push(x);
			check[x] = true;
		}
	}
	cout << ans << endl;
	rep(i,n) cout << write[i] << " ";
}
