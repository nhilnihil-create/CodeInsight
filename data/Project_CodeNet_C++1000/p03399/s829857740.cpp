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
	int a,b,c,d;
	cin >> a >> b >> c >>d;
	int mi = a+c;
	mi = min (mi,a+d);
	mi = min (mi, b+c);
	mi = min (mi, b+d);
	cout << mi << endl;
	return 0;
}
