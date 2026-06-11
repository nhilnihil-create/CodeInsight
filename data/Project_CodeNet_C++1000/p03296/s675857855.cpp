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
	const int c = 10000;
	int n,dp[110][10010] = {},a[110];
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	int mi = 0,mii = 0,mi2 = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < c;j++){
			dp[i][j] = (j != mii ? mi : mi2) + (a[i] != j);
		}
		mi = INF;
		mi2 = INF;
		for(int j = 0;j < c;j++){
			if(mi2 > dp[i][j]) swap(mi2,dp[i][j]);
			if(mi > mi2){
				swap(mi,mi2);
				mii = j;
			}
		}
	}
	cout << mi << endl;
}