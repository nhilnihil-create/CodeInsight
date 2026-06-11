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
	int n,ans = 0;
	string s[610];
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> s[i];
		s[i] += s[i];
	}
	for(int i = 0;i < n;i++) s[i + n] = s[i];
	for(int sa = -(n - 1);sa <= n - 1;sa++){
		int sum = 0;
		bool calced = false;
		for(int a = 0;a < n;a++){
			int b = a + sa;
			if(b < 0 || n <= b) continue;
			if(!calced){
				for(int i = 0;i < n;i++){
					for(int j = i + 1;j < n;j++) sum += (s[a + i][b + j] == s[a + j][b + i]);
				}
				calced = true;
			}
			else{
				for(int i = 1;i < n;i++){
					sum = sum - (int)(s[a + i - 1][b - 1] == s[a - 1][b + i - 1]) + (int)(s[a + n - 1 - i][b + n - 1] == s[a + n - 1][b + n - 1 - i]);
				}
			}
			if(sum == n * (n - 1) / 2) ans++;
		}
	}
	cout << ans << endl;
}