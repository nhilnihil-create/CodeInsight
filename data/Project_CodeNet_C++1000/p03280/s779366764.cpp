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
	int area = (a * b) -a -b +1;
	cout << area << endl;
	return 0;
}
