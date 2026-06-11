#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);i++)
#define urep(i,a,n) for(ll i = (a);i>=(n);i--)
#define all(x) (x).begin(),(x).end()
#define INF 1e9
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll dx[4] = { 1,-1,0,0 };
ll dy[4] = { 0,0,1,-1 };
ll N, M, Q, H, W, D, L, R, K, X;
ll A;
ll B;
ll ans;
string S;
ll a[100000000];
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
ll minnum, maxnum;
ll minpos = 1, maxpos = 1;
int main() {
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> a[i];
		minnum = min(minnum, a[i]);
		if (a[i] == minnum)
			minpos = i;
		maxnum = max(maxnum, a[i]);
		if (a[i] == maxnum)
			maxpos = i;
	}
	cout << N * 2 << endl;
	ll count = 0;
	if (abs(maxnum) < abs(minnum)) {
		rep(i, 1, N + 1) {
			if (0 < a[i]) {
				cout << minpos << " " << i << endl;
				count++;
			}
		}
		urep(i, N, 2) {
			cout << i << " " << i - 1 << endl;
			count++;
		}
		rep(i, count, N * 2) {
			cout << 1 << " " << 1 << endl;
		}
	}
	else {
		rep(i, 1, N + 1) {
			if (a[i] < 0) {
				cout << maxpos << " " << i << endl;
				count++;
			}
		}
		rep(i, 1, N) {
			cout << i << " " << i + 1 << endl;;
			count++;
		}
		rep(i, count, N * 2) {
			cout << N << " " << N << endl;
		}
	}
	cin >> ans;
	return 0;
}