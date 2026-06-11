//include,using,define等
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
 
// ===============================================================
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
using ui = unsigned int;
using qul = queue<ll>;
using pql = priority_queue<ll>;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#pragma region header
//#define int long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define INF (ll)10000000000000000
#define mod (ll)1000000007
#define P pair<lint,lint>
template <class T>
bool chmax(T & a, const T & b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
template <class T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion
lint n;
vector<int> a;
bool isOK(int index, int key) {
	if (a[index] >= key) return true;
	else return false;
}
 
int binary_search(int key) {
	int ng = -1; 
	int ok = (int)a.size();
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		if (isOK(mid, key)) ok = mid;
		else ng = mid;
	}
	if (a[ok] == key)
		return ok;
	else
		return -1;
}
 
 
int main(void) {
    vl e = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184};
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	lint ans = 0;
	lint cnt = 0;
 	while (a.size() > 1) {
		for (int i = 30; i >= 0; i--) {
			if (a[a.size() - 1] >= e[i]) {
				cnt = e[i + 1];
				break;
			}
		}
		int d = a[a.size() - 1];
		a.pop_back();
		int x = binary_search(cnt - d);
		if (x != -1 && x != a.size()) {
			ans++;
            a.erase(a.begin() + x);
		}
	}
	printf("%lld\n", ans);
 
    return 0;
}