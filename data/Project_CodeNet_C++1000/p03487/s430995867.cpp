#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <cstdlib>
#define rep(i,n) for(int i = 0;i<(n);i++);
#define all(a) (a).begin(),(a).end()
using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 100100100100100;
ll gcd(ll a,ll b) {//a>b
	if (a < b)swap(a, b);
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main() {
	ll N;
	cin >> N;
	map<ll, ll> num;
	ll n = 0;
	vector<ll> M;
	for (int i = 0; i < N; i++) {
		cin >> n;
		num[n]++;
		if (num[n] == 1) {
			M.push_back(n);
		}
	}
	ll ans = 0;
	for (int i = 0; i < M.size();i++) {
		if (num[M[i]] < M[i]) ans += num[M[i]];
		else if (num[M[i]] > M[i]) ans += num[M[i]] - M[i];/*4 3 3 3  -> 28*/
	}
	cout << ans << endl;
}