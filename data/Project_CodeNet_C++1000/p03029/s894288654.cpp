#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
int main() {

	int a, p;
	cin >> a >> p;
	p = p + a * 3;
	cout << (p - (p % 2)) / 2 << endl;
	return 0;

}