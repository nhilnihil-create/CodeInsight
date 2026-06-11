#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(v) v.begin(), v.end()
#define revall(v) v.rbegin(), v.rend()
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){ if(y<h && y>=0 && x<w && x>=0) return true; return false; }
template<class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return true; } return false; }





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,z,w;cin >> n >> z >> w;
	vector<int> a(n);
	rep(i,n) cin >> a.at(i);
	if(n == 1){
		cout << abs(a.at(0) - w) << endl;
		return 0;
	}
	int ans = max(abs(a.at(n - 1) - w), abs(a.at(n - 2) - a.at(n - 1)));
	cout << ans << endl;
}
