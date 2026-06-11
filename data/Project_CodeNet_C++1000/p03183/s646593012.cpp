#include <bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
#define MP make_pair
#define ld long double
 
using namespace std;
 
const int N = 5e5 + 123;
const ll mod = 1e9 + 7;

struct Blocks{
	int s, w;
	ll v;
	Blocks(int ww=0, int ss=0, ll vv=0){
		v = vv, s = ss, w = ww;
	}
}a[N];

int n;
ll dp[1010][20100];
int was[N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		int s, w;
		ll v;
		cin >> w >> s >> v;
		a[i] = Blocks(w, s, v);
		//cerr << a[i].v << " " << v << "\n";
	}

	sort(a + 1, a + n + 1, [](Blocks x, Blocks y){
		return x.s + x.w < y.s + y.w;	
	});

	ll res = 0;
	was[0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 20000;j >= 0;j--){
			dp[i][j] = dp[i - 1][j];
		}
		for(int j = 20000;j >= a[i].w;j--){		
			int x = j - a[i].w;
			if(was[x] == 1 && x <= a[i].s){
				dp[i][j] = max(dp[i][j], dp[i - 1][x] + a[i].v);
		//		cerr << a[i].v << "\n";
				was[j] = 1;
			}
			res = max(res, dp[i][j]);
		}
	}
	cout << res;
	return 0;
}
