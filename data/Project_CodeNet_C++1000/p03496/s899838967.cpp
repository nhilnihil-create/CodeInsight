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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n;i++) {
		cin >> a[i];
	}

	int min_i = 0;
	int max_i = 0;

	for (int i = 1; i < n;i++) {
		if (a[i] < a[min_i]) {
			min_i = i;
		}
		if (a[i] >a[max_i]) {
			max_i = i;
		}
	}
	
	cout << 2 * n -1<< endl;
	if ((-1*a[min_i]) <= (a[max_i])) {
		max_i++;
		for (int i = 1; i <=n;i++) {
			cout << max_i << " " << i << endl;
		}
		for (int i = 1; i < n;i++) {
			cout << i << " " << i+1 << endl;
		}
	}
	else {
		min_i++;
		for (int i = 1; i <= n;i++) {
			cout << min_i << " " << i << endl;
		}
		for (int i = n; i >1;i--) {
			cout << i << " " << i - 1 << endl;
		}
	}
}
	
