#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
#include <unordered_map>
#include <fstream>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef pair<ll,ll> P;
typedef pair<int,int> pii;
typedef vector<P> vpl;
typedef tuple<ll,ll,ll> tapu;
#define rep(i,n) for(int i=0; i<(n); i++)
#define REP(i,a,b) for(int i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {1,-1,0,0,1,-1,1,-1};
ll dx[8] = {0,0,1,-1,1,-1,-1,1};
const double pi = acos(-1);
const double eps = 1e-7;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){
	if(a>b){
		a = b; return true;
	}
	else return false;
}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){
	if(a<b){
		a = b; return true;
	}
	else return false;
}
template<typename T> inline void print(T &a){
    rep(i,a.size()) cout << a[i] << " ";
    cout << "\n";
}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << "\n";}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << "\n";
}
const int mod = 1e9 + 7;
//const int mod = 998244353;

double dp[303][303][303];
vl cnt(3);
ll n;

double rec(ll x, ll y, ll z){
	if(dp[x][y][z] != -1) return dp[x][y][z];
	dp[x][y][z] = 0.0;
	double num = 1.0 * n / (double)x;
	if(x != y){
		dp[x][y][z] += (rec(x-1,y,z) + num) * (x-y) / (double)x;
	}
	if(y != z){
		dp[x][y][z] += (rec(x,y-1,z) + num) * (y-z) / (double)x;
	}
	if(z > 0){
		dp[x][y][z] += (rec(x,y,z-1) + num) * z / (double)x;
	}
	return dp[x][y][z];
}

int main(){
	cin >> n;
	vl a(n); rep(i,n) cin >> a[i], a[i]--;
	rep(i,n) cnt[a[i]]++;
	cnt[1] += cnt[2];
	cnt[0] += cnt[1];
	rep(i,cnt[0]+1) rep(j,cnt[1]+1) rep(k,cnt[2]+1) dp[i][j][k] = -1;
	dp[0][0][0] = 0;
	printf("%.10f\n",rec(cnt[0],cnt[1],cnt[2]));
}