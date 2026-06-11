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
	int ans =700;
	vector <char> a(3);
	for (int i =0 ; i<3;i++) {
		cin >> a[i];
		if (a[i] == 'o') ans += 100;
	}
	cout << ans << endl;
	return 0;
}
