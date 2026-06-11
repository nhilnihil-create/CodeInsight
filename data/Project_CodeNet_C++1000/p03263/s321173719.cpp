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
using namespace std;
using ll = long long;

int main() {
	int H, W; cin >> H >> W;
	vector<vector<int>> vec(H, vi(W));
	rep(i, H)rep(j, W) cin >> vec[i][j];

	vector<vector<int>> answers;
	int direction = 1;
	int j = -1;
	for (int i = 0; i < H; i++) {
		if (direction == 1) {
			for (int j = 0; j < W; j++) {
				if (vec[i][j] % 2 == 1) {
					if (j == W - 1) {
						if (i == H - 1) goto endloop;
						answers.push_back({ i,j,i + 1,j });
						vec[i][j]--;
						vec[i + 1][j]++;
					}
					else {
						answers.push_back({ i,j,i,j + 1 });
						vec[i][j]--;
						vec[i][j + 1]++;
					}
				}
			}
			direction *= -1;
		}
		else {
			for (int j = W-1; j > -1; j--) {
				if (vec[i][j] % 2 == 1) {
					if (j == 0) {
						if (i == H - 1) goto endloop;
						answers.push_back({ i,j,i + 1,j });
						vec[i][j]--;
						vec[i + 1][j]++;
					}
					else {
						answers.push_back({ i,j,i,j - 1 });
						vec[i][j]--;
						vec[i][j - 1]++;
					}
				}
			}
			direction *= -1;
		}

	}
endloop:
	cout << answers.size() << endl;

	for (auto a : answers) {
		cout << a[0]+1 << " " << a[1]+1 << " " << a[2]+1 << " " << a[3]+1 << endl;
	}
}