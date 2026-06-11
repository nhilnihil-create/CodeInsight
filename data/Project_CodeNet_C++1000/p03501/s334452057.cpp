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
	int n,a,b;
	cin >> n >> a >>b;
	int mi = n * a;
	mi = min(mi,b);
	cout << mi << endl;
	return 0;

}
