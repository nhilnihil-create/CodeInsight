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
	string a;
	string b;
	cin >> a;
	cin >> b;
	for (int i =0;i<3;i++) {
		if (a[i] != b[2-i]) {
			cout << "NO" << endl;
		   	return 0;
		}
	}
	cout << "YES" << endl;
	
}
