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
#include <cmath>
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
using namespace std;
using ll = long long;


int main() {
	int N, K; cin >> N >> K;
	string s; cin >> s;
	char prev = s[0];
	vi vec;
	vec.push_back(0);
	for (int i = 0; i < N; i++) {
		if (s[i] == prev) vec.back()++;
		else {
			vec.push_back(1);
			prev = s[i];
		}
	}
	vi acc(vec.size() + 1);
	for (int i = 1; i < acc.size(); i++) {
		acc[i] = acc[i - 1] + vec[i-1];
	}

	int ans = 0;
	if (s[0] == '0') {
		for (int s = 0; s < acc.size(); s += 2) {
			int g = min(s + 2 * K, int(acc.size()) - 1);
			if (s == 0) {
				ans = max(ans, acc[g]);
			}
			else {
				ans = max(ans, acc[g] - acc[s - 1]);
			}
		}

	}
	else {
		for (int s = 1; s < acc.size(); s += 2) {
			int g = min(s + 2 * K, int(acc.size()) - 1);
			ans = max(ans, acc[g] - acc[s - 1]);
		}
	}

	cout << ans << endl;
}