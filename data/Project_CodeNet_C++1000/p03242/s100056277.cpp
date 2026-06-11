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
void print (int);
 
int main() {
	int x;
	cin >> x;
	int a,b,c;
	a = x /100;
	b = (x % 100) /10;
	c = x % 10;
	print(a);
	print(b);
	print(c);
	cout << endl;

	return 0;
}

void print(int a) {
	if (a == 1) cout << 9;
	else cout << 1;
}
