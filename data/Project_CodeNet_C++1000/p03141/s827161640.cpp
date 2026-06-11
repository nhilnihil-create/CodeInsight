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

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,a[100010],b[100010];
	vector<P> vec;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i];
		vec.emplace_back(a[i] + b[i],i);
	}
	sort(all(vec),greater<P>());
	int ans = 0;
	for(int i = 0;i < n;i++){
		if(i % 2 == 0) ans += a[vec[i].second];
		else ans -= b[vec[i].second];
	}
	cout << ans << endl;
}