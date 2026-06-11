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
//using ll = long long;
using P = pair<int,int>;

ostream &operator<<(ostream &os,const P &p){ return os << "" << p.first << " " << p.second << ""; }

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n;
	cin >> n;
	vector<P> ans;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if((n % 2 && i + j != n) || (n % 2 == 0 && i + j != n + 1)){
				ans.emplace_back(i,j);
			}
		}
	}
	cout << ans.size() << endl;
	for(P p : ans){
		cout << p << endl;
	}
}
