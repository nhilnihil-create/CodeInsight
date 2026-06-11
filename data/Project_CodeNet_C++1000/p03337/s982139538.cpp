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
	int ma;
	cin >> a >> b;
	ma = a +b;
	ma = max(ma, a-b);
	ma = max (ma, a*b);
	cout << ma << endl;
	return 0;
}
