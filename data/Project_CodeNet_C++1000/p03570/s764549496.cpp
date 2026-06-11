#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define rep(i,n)	for(int i=0;i<n;i++)
#define srep(i,a,n)	for(int i=a;i<n;i++)
#define REP(i,n)	for(int i=0;i<=n;i++)
#define SREP(i,a,n)	for(int i=a;i<=n;i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define RREP(i,n)	for(int i=n;i>=0;i--)
#define all(a)	(a).begin(),(a).end()
#define mp(a,b)	make_pair(a,b)
#define mt	make_tuple
#define pb	push_back
#define fst	first
#define scn second
#define bicnt(x)	__buildin__popcount(x)
#define debug(x)	cout<<"debug: "<<x<<endl
#define DEBUG 0

const ll inf = (ll)1e18;
const ll mod = 1e9 + 7;
const ld eps = 1e-9;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

int cnt[1 << 26];

int main() {
	string s;	cin >> s;
	int n = s.size();
	rep(i, 1 << 26)	cnt[i] = mod;
	cnt[0] = 0;
	int ret = 0;
	int id = 0;
	rep(i, n) {
		id ^= (1 << (s[i] - 'a'));
		ret = cnt[id] + 1;
		rep(j, 26) {
			int from = id ^ (1 << j);
			ret = min(ret, cnt[from] + 1);
		}
		cnt[id] = min(cnt[id], ret);
	}
	cout << ret << endl;
	return 0;
}