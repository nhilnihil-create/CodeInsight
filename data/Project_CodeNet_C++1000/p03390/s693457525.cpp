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
 
const int INF=2e+18;
const double EPS=1e-9;
const int MOD=1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

signed main(){
	int q;
	cin >> q;
	for(int i = 0;i < q;i++){
		int a,b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		if(a == b) cout << (a - 1) * 2 << endl;
		else{
			int low = a,up = INF;
			while(up - low > 1){
				int mid = (up + low) / 2;
				if(mid > (a * b - 1) / mid) up = mid;
				else low = mid;
			}
			cout << up + (a * b - 1) / up - 2 << endl;
		}
	}
	return 0;
}