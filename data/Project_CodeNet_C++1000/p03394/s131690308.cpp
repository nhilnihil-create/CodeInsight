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

signed main(){
	int n,ni,sum,yaku;
	cin >> n;
	if(n == 3){
		printf("2 5 63\n");
		return 0;
	}
	ni = n - 2;
	while(ni * 2 > 30000 || ni * (ni + 1) / 2 % 3 || (n - ni) % 2) ni--;
	for(int i = 0;i < ni;i++) cout << (i ? " " : "") << (i + 1) * 2;
	if(n - ni > 5000){
		cout << " 30000";
		ni++;
	}
	for(int i = 0;i < n - ni;i++) cout << " " << (i * 2 + 1) * 3;
	return 0;
}