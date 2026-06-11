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

int main()
{
	int h, w,d;
	cin >> h >> w >>d;
	map<int,P> mp;
	rep(i,h){
		rep(j,w){
			int a;
			cin >> a;
			mp[a] = {i,j};
		}
	}
	vector<int> cost[d+1];
	for(int i = 1; i <= d; i++) {
		cost[i].push_back(0);
		int ind = i;
		int bef = 0;
		while(ind + d <= h * w){
			P from = mp[ind];
			P to = mp[ind + d];
			int to_next = 0;
			to_next = abs(from.first - to.first) + abs(from.second - to.second);
			//debug(to_next);
			cost[i].push_back(bef + to_next);
			bef += to_next;
			ind += d;
		}
		//for(auto x:cost[i]){
		//	cout << x <<" ";
		//} cout << endl;
	}
	int q;
	cin >> q;
	rep(i,q){
		int l, r;
		cin >> l >> r;
		int root = l %d;
		if(root == 0)root+= d; // cost[root]を見る
		// l ,  rまで行くまでに何回か
		int toL = (l + d - 1) / d - 1; 
		int toR = (r + d - 1) / d - 1; 
	//	debug(toL);
	//	debug(toR);
	//	debug(cost[root][toL]);
	//	debug(cost[root][toR]);
		cout << cost[root][toR] - cost[root][toL] << endl;
	}
}
