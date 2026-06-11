#include "bits/stdc++.h"
#define esc(ret) cout << (ret) << endl,quick_exit(0)
#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define repD(i,s,t) for(int i = (int)(s); i >= (int)(t); --i)
#define rep(i,n) repU(i,0,(n) - 1)
#define rep1(i,n) repU(i,1,(n))
#define all(v) begin(v),end(v)
#define vct vector
#define prique priority_queue
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define qceil(n,d) ((n) > 0 ? ((n) - 1) / (d) + 1 : (n) / (d))
#define parity(a,b) ((a) & 1 == (b) & 1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef pair<db,int> pdi;

const pii dir[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int mod = 1e9 + 7;
const int inf32 = (1 << 30) - 1;
const ll inf64 = (1LL << 62) - 1;

string S;
int X,Y;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> S >> X >> Y;
	deque<int> x,y;
	x.pub(0);
	int t = 0;
	for(char c : S){
		if(c == 'T'){
			t = 1 - t;
			if(t) y.pub(0);
			else x.pub(0);
		}else{
			if(t){
				++y.back();
			}else{
				++x.back();
			}
		}
	}
	
	bool dp[2][2][16002] = {};
	dp[0][1][x.front()] = 1;
	//cout << x.front() << endl;
	x.pof();
	t = 0;
	while(!x.empty()){
		dp[t][1][0] |= dp[t][0][0];
		dp[t][0][0] |= dp[t][1][0];
		int l = x.front();
		x.pof();
		//cout << l << endl;
		rep(i,2)rep(j,8001){
			 dp[1 - t][i][j + l] |= dp[t][i][j];
			 if(l < j){
			 	dp[1 - t][i][j - l] |= dp[t][i][j];
			 }else{
			 	dp[1 - t][1 - i][l - j] |= dp[t][i][j];
			 }
			 dp[t][i][j] = 0;
		}
		t = 1 - t;
	}
	dp[t][1][0] |= dp[t][0][0];
	dp[t][0][0] |= dp[t][1][0];
	bool res1 = X > 0 ? dp[t][1][X] : dp[t][0][-X];
	
	bool dp2[2][2][16002] = {};
	dp2[0][0][0] = dp2[0][1][0] = 1;
	t = 0;
	while(!y.empty()){
		int l = y.front();
		y.pof();
		rep(i,2)rep(j,8001){
			 dp2[1 - t][i][j + l] |= dp2[t][i][j];
			 if(l < j){
			 	dp2[1 - t][i][j - l] |= dp2[t][i][j];
			 }else{
			 	dp2[1 - t][1 - i][l - j] |= dp2[t][i][j];
			 }
			 dp2[t][i][j] = 0;
		}
		t = 1 - t;
		dp2[t][1][0] |= dp2[t][0][0];
		dp2[t][0][0] |= dp2[t][1][0];
	}
	
	bool res2 = dp2[t][1][abs(Y)];
	//cout << res1 << ' ' << res2 << endl;
	if(res1 & res2) cout << "Yes\n";
	else cout << "No\n";
}


