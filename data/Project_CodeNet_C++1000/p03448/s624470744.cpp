#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int num[3];
	for (int i = 0; i < 3; i++) cin >> num[i];
	int X; cin >> X;
	int count = 0;
	for (int i = 0; i <= num[0]; i++) {
		for (int j = 0; j <= num[1]; j++) {
			for (int k = 0; k <= num[2]; k++) {
				if (500 * i + 100 * j + 50 * k == X) count++;
			}
		}
	}
	cout << count << endl;

	return 0;
}