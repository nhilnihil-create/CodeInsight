
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
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;




int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n;i++) {
		cin >> a[i];
	}
	
	int cnt = 0;
	for (int i = 1;i < n;i++) {
		if (a[i] == a[i - 1]) {
			a[i] = 10000;
			cnt++;
		}
	}

	cout << cnt << endl;
}

