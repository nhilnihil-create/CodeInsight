#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	x3 = x2 + y1 - y2;
	y3 = y2 - x1 + x2;
	x4 = x1 - y2 + y1;
	y4 = y1 + x2 - x1;
	cout << x3 << endl;
	cout << y3 << endl;
	cout << x4 << endl;
	cout << y4 << endl;
	return 0;
}
