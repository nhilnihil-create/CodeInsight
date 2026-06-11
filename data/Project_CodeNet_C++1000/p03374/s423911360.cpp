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
#define double long double
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

signed main(){
	int n,c,ma = 0,x[100010],v[100010],sum = 0;
	cin >> n >> c;
	for(int i = 1;i <= n;i++){
		cin >> x[i] >> v[i];
		sum += v[i];
	}
	x[0] = 0;
	x[n + 1] = c;
	priority_queue<int> que;
	int tv = 0,td = 0,tsum = sum - 2 * x[n];
	que.push(0);
	for(int i = n;i >= 1;i--){
		tv += v[i];
		td += x[i + 1] - x[i];
		que.push(tv - td);
		tsum += 2 * (x[i] - x[i - 1]) - v[i];
		chmax(ma,tsum + que.top());
	}
	while(que.size()) que.pop();
	que.push(0);
	tv = 0,td = 0,tsum = sum - 2 * (c - x[1]);
	for(int i = 1;i <= n;i++){
		tv += v[i];
		td += x[i] - x[i - 1];
		que.push(tv - td);
		tsum += 2 * (x[i + 1] - x[i]) - v[i];
		chmax(ma,tsum + que.top());
	}
	cout << ma << endl;
	return 0;
}