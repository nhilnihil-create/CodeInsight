#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
 
int main() {
	int n,k;
	cin >> n >> k;
	if (n%k ==0) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
	return 0;
}
