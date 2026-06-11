//inlclude before define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
#include<assert.h>
//#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef pair<int, int> P1;
typedef long long int ll;

//define
#define INF 1e9
#define NUM 1000000007
#define all(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))

//function

/*ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}*/

/*ll lcm(ll a,ll b) {
	ll g = gcd(a, b);
	return a * (b / g);
}*/

int main() {
	ll n,p;
	cin >> n >> p;
	ll ans = -1;
	if (n == 1) {
		ans = p;
	} else if (p == 1) {
		ans = 1;
	} else {
		ll num=0;
		double a = 1.0 / (double)n;
		for (int i = 1; i<= pow(p,a)+1; i++) {
			num = (ll)pow(i, n);
			if (p%num == 0) ans = i;
			else if (p < num)break;
		}
		if (ans == -1) ans = 1;
	}
	cout << ans << endl;
	return 0;
}
