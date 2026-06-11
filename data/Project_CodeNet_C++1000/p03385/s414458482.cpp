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
	vector <char> a(3);
	for (int i =0; i< 3; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == 'a' && a[1] == 'b' && a[2] == 'c') cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
