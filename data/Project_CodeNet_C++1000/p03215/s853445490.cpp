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
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int n,k,a[1010];
	cin >> n >> k;
	for(int i = 0;i < n;i++) cin >> a[i];
	vector<int> b;
	for(int i = 0;i < n;i++){
		int sum = 0;
		for(int j = i;j < n;j++){
			sum += a[j];
			b.push_back(sum);
		}
	}
	int ans = 0;
	vector<bool> ok(b.size(),true);
	for(int i = 60;i >= 0;i--){
		int cnt = 0;
		for(int j = 0;j < b.size();j++){
			if(ok[j] && ((b[j] >> i) & 1)) cnt++;
		}
		if(cnt >= k){
			ans += (1ll << i);
			for(int j = 0;j < b.size();j++){
				if(ok[j] && !((b[j] >> i) & 1)) ok[j] = false;
			}
		}
	}
	cout << ans << endl;
}