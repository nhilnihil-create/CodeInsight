#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,n) for(int i=1;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	debug("debug test\n");
   	int n,m;cin>>n>>m;
	vint f(10, 0);
	vint h = {-10000, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	vint dp(10002, -100000);
	rep(i, m){
		int a;cin>>a;
		f[a] = 1;
		//chmax(dp[h[a]], a);
	}
	dp[0] = 0;
	reps(i, n+1){
		reps(j, 10){
			if(f[j] == 1){
				if(i-h[j] >= 0&& dp[i-h[j]] >= 0){
					chmax(dp[i], dp[i-h[j]]+1);
				}
			}
		}
	}
	int k = dp[n];
	//cout << k << endl;
	rep(i, k){
		for(int j = 9;j > 0;j--){
			if(f[j] == 1&&n-h[j] >= 0&&dp[n-h[j]]==k-1-i){
				//cout << j << ' ' << n << endl;;
				n -= h[j];
				cout << j;
				break;
			}
		}
	}
	cout << endl;
	
	return 0;
}
