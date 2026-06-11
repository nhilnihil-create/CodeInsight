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
#include<cmath>
#include<limits>
#define ll long long
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
using namespace std;

bool check(string sub, string t) {
	for (int i = 0; i < t.size(); i++) {
		if (sub[i] != t[i]) {
			if (sub[i] != '?') return false;
		}
	}
	return true;
}
int main() {
	string ss, t; cin >> ss >> t;

	if (t.size() > ss.size()) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	else {
		for (int index = ss.size() - t.size(); index >= 0; index--) {
			string sub = ss.substr(index, t.size());
			if (check(sub, t)) {
				for (int i = index; i < index + t.size(); i++) {
					ss[i] = t[i - index];
				}
				for (int i = 0; i < ss.size(); i++) {
					if (ss[i] == '?') ss[i] = 'a';
				}
				cout << ss << endl;
				return 0;
			}
		}
	}

	cout << "UNRESTORABLE" << endl;
}