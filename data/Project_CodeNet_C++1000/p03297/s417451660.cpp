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

template<class T>
T gcd(T a,T b){
	return b ? gcd(b,a % b) : a;
}

signed main(){
	int t;
	cin >> t;
	for(int _t = 0;_t < t;_t++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int g = gcd(b,d);
		if(a >= b && d >= b && (b - a % b - 1) / g * g + a % b <= c) Yes();
		else No();
	}
}