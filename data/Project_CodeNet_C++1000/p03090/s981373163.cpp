#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
#include<tuple>
#include<stack>

#define _USE_MATH_DEFINES
#include<math.h>


using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int BIG_NUM = 1000000005;
const ll INF = 1000000000000000000;

//const vector<vector<int>> DIR{ {1,0},{0,1},{-1,0},{0,-1} };

//const double EPS = 1e-10;


int main() {
	int n;
	cin >> n;
	vector<pii> edge;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (n % 2 == 0) {
				if (i + j != n - 1) {
					edge.emplace_back(make_pair(i + 1, j + 1));
				}
			}
			else {
				if (i + j != n - 2) {
					edge.emplace_back(make_pair(i + 1, j + 1));
				}
			}
		}
	}

	std::cout << edge.size() << endl;
	for (pii e : edge) {
		std::cout << e.first << " " << e.second << endl;
	}
} 


