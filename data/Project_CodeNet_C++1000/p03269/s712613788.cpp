#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

struct edge{ int from,to,cost; };

vector<edge> vec;

signed main(){
	int n,m,l,keta = 0,tmp;
	cin >> l;
	tmp = l;
	while(tmp){
		keta++;
		tmp /= 2;
	}
	n = keta;
	for(int i = keta - 2;i >= 0;i--){
		vec.pb({i,i + 1,0});
		vec.pb({i,i + 1,l / 2});
		if(l % 2) vec.pb({0,i + 1,l - 1});
		l /= 2;
	}
	cout << n << " " << vec.size() << endl;
	for(edge e : vec) cout << e.from + 1 << " " << e.to + 1 << " " << e.cost << endl;
	return 0;
}