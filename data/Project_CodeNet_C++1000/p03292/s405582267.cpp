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
	vector <int> a(3);
	for (int i =0 ; i <3;i++) cin >> a[i];
	sort(a.begin(), a.end());
	int cost = abs(a[1] - a[0]) + abs(a[2] - a[1]);
	cost =  min(cost, abs(a[2] - a[0]) + abs(a[1]-a[2]));
	cout << cost << endl;
	return 0;
}
