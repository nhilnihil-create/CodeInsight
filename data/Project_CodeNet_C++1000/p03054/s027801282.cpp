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

//#define int long long
//using ll = long long;
using P = pair<int,int>;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+9;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int h,w,n,sx,sy;
	string s,t;
	cin >> h >> w >> n >> sx >> sy >> s >> t; sx--;sy--;
	int xmin = 0,xmax = h,ymin = 0,ymax = w;
	for(int i = n - 1;i >= 0;i--){
		if(t[i] == 'U') xmax = min(h,xmax + 1);
		else if(t[i] == 'D') xmin = max(0,xmin - 1);
		else if(t[i] == 'L') ymax = min(w,ymax + 1);
		else if(t[i] == 'R') ymin = max(0,ymin - 1);
		
		if(s[i] == 'U') xmin++;
		else if(s[i] == 'D') xmax--;
		else if(s[i] == 'L') ymin++;
		else if(s[i] == 'R') ymax--;
		if(xmin >= xmax || ymin >= ymax){
			NO();
			return 0;
		}
	}
	if(xmin <= sx && sx < xmax && ymin <= sy && sy < ymax) YES();
	else NO();
}
