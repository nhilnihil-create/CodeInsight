#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<cmath>
#include<stack>
#include<string.h>
#include <iomanip>
#define rep(i,n) for(int i = 0;i<n;i++)
using ll = long long; 
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	ll n,k;
	cin >> n >> k;
	ll ans = 0;
	if(k%2==0) {
		ll a = n/k;
		ll b = n/(k/2) - a;
		ans = a*a*a+b*b*b;
		cout << ans << endl;
		return 0;
	}
	if(k%2 == 1) {
		ll c = n/k;
		ans = c*c*c;
		cout << ans << endl;
		return 0;
	}
}