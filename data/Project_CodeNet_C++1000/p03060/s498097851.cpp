#include<iostream> 
#include<stdio.h>
#include<string>
#include<iomanip> 
#include<vector> 
#include<map> 
#include<set> 
#include<algorithm> 
#include<numeric> 
#include<limits> 
#include<bitset> 
#include<functional> 
#include<type_traits> 
#include<queue> 
#include<stack> 
#include<array> 
#include<random> 
#include<utility> 
#include<cstdlib> 
#include<ctime>
//#define _LIBCPP_DEBUG 0
//#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define all(a) (a).begin(),(a),end()
#define rep(i,n) for (ll i = 0; i < (n); ++i)	
//setprecision(16)

void outi(int x) { cout << x << endl; }
void outl(ll x) { cout << x << endl; }
void outs(string x) { cout << x << endl; }
ll max(ll a, ll b) {
	ll max;
	if (a > b) max = a;
	else max = b;
	return max;
}
ll min(ll a, ll b) {
	ll min;
	if (a < b) min = a;
	else min = b;
	return min;
}
//---------------------------------------------------------------

int main() {
	int n;
	cin >> n;
	int v[22];
	int c[22];

	rep(i, n) {
		cin >> v[i];
	}
	rep(i, n) {
		cin >> c[i];
	}

	int ans = 0;
	rep(i, n) {
		int dif = v[i] - c[i];
		if (dif >= 0) {
			ans += dif;
		}
	}

	cout << ans << endl;
}