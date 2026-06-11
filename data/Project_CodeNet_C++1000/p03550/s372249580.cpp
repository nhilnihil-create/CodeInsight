#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;



int main() {
	int n, z, w;
	cin >> n >> z >> w;

	vector<int> a(n);
	for (int i = 0; i < n;i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << abs(a[0] - w) << endl;
	}
	else {
		cout << max(abs(a[n - 1] - w), abs(a[n - 2] - a[n - 1])) << endl;
	}

}
