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
#include<math.h>
#include<iomanip>
#include<functional>
using namespace std;

#define ll long long
using vt = ll; //ここで数値の型を変えられる
#define rep(i, n) for (vt i = 0; i < (vt)(n); i++)
#define reps(i, s, n) for(vt i = (vt) (s); i < (vt) (n); i++) 
#define all(v) v.begin(), v.end()
#define P pair<int, int>
const ll  MOD = 1000000007;

int main() {
	ll r, g;
	cin >> r >> g;
	cout << 2 * g - r;
	return 0;
}