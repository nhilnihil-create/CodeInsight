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
	int a,b;
	cin >> a >> b;
	for (int i=1; i <=3;i++) {
		if ((a * b * i) %2 ==1) {
			cout << "Yes" <<endl;
			return 0;
		}
	}
	cout << "No" <<endl;
	return 0;
}
