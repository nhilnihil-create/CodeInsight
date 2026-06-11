#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 3500;

int main() {
	ll n;
	cin >> n;

	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j <= MAX; j++) {
			ll a = 4 * i * j - n * (i + j);
			ll b = n * i * j;

			if (a > 0 && b % a == 0) {
				//cout << a << " " << b << endl;
				ll c = b / a;
				cout << i << " " << j << " " <<c << endl;
				//cout << (4 * c * i * j) / (j * c + c * i+i * j) << endl;
				return 0;
			}
		}
	}
}