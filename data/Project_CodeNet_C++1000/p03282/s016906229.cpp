#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
const int MAX_N = 1000000000;
const int MAX_L = 100000000;
const int MAX_SQRT_B = 10000;
const int INF = 1000000000;
typedef int64_t ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

string S;
ll K;

int main() {
	cin >> S >> K;

	ll cnt = 0;
	for (int i = 0; i < S.size(); i++)
	{
		int tmp = S.at(i) - '0';

		if (tmp == 1) {
			cnt++;
		}
		else {
			if (K > cnt) {
				cout << tmp << endl;
				return 0;
			}
			else {
				cout << 1 << endl;
				return 0;
			}
		}

	}
	cout << 1 << endl;
	return 0;	
}