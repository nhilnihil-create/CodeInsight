#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <tuple>
#include <utility>
#include <vector>
#define ll long long
#define itn int
#define endl '\n'
#define co(ans) cout<<ans<<endl
#define COYE cout<<"YES"<<endl
#define COYe cout<<"Yes"<<endl
#define COye cout<<"yes"<<endl
#define CONO cout<<"NO"<<endl
#define CONo cout<<"No"<<endl
#define COno cout<<"no"<<endl
#define FORE(i,a) for(auto &i:a)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n)  FFOR(i,1,n)
#define PB push_back
#define MP make_pair
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort((V).begin(),(V).end())
#define REVERSE(V) reverse((V).begin(),(V).end())
#define EACH(V,i) for(typeof((V).begin()) i=(V).begin();i!=(V).end();++i)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define INF ((1LL<<62)-(1LL<<31))
#define EPS 1e-10
#define PI 3.141592653589793238
#define MOD 1000000007
#define MMOD 998244353
#define MAX 2010101
using namespace std;
using Edge=pair<ll,ll>;
using Graph=vector<vector<int>>;
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T>inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef long long LL;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

signed main(){
	ll n, C; cin >> n >> C;
	vector<ll> x(n, 0), c(n, 0), x1(n), c1(n), q(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> c[i]; q[i] = c[i];
		x1[i] = C - x[i]; c1[i] = c[i];
	}
	reverse(x1.begin(), x1.end());
	reverse(c1.begin(), c1.end());
	for(int i = 1; i < n; i++){
		c[i] += c[i - 1];
		c1[i] += c1[i - 1];
	}
	vector<ll> data1(n + 1, 0), data2(n + 1, 0);
	for(int i = 1; i <= n; i++){
		data1[i] = c[i - 1] - x[i - 1];
		data2[i] = c1[i - 1] - x1[i - 1];
	}
	vector<ll> data_left(n + 1, 0), data_right(n + 1, 0);
	for(int i = 1; i  <= n; i++){
		data_left[i] = max(data_left[i - 1], data1[i]);
		data_right[i] = max(data_right[i - 1], data2[i]);
	}
	ll ans = 0;
	for(int left = 0; left <= n; left++){
		if(left == 0) ans = max(ans, data_right[n]);
		ans = max(ans, data1[left] - x[left - 1] + data_right[n - left]);
	}
	for(int right = 0; right <= n; right++){
		if(right == 0) ans = max(ans, data_left[n]);
		else ans = max(ans, data2[right] - x1[right - 1] + data_left[n - right]);
	}
	cout << ans << endl;
}