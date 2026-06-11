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
const ll INF = 10010010010;
typedef pair<ll, ll> P;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {//a>b
	if (a < b)swap(a, b);
	if (a % b == 0) return b;
	else return gcd(b, a % b);
}

int main() {
	ll R, G, B, N;
	cin >> R >> G >> B >> N;//Ra + Gb + Bc = N
	ll n = N / min(R, min(G, B));
	ll ans = 0;
	for (int i = 0; i <= n; i++) {// 1 2 3 4
		for (int j = 0; j <= n; j++) {
			if ((N - i * R - j * G) % B == 0 && N - i * R - j * G >= 0)ans++;
		}
	}
	cout << ans << endl;
}