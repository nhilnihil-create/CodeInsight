#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int a, b,c;
	int x, y;
	int price_min;
		cin >> a >> b >> c >> x >> y;
		price_min = a * x + b * y;
			for (int i = 0; i <= max(x,y)*2; i+=2) {
					if (c * i + max((x - (i / 2)), 0) * a + max((y - (i / 2)), 0)*b< price_min) {
						price_min = c * i +max( (x - (i/ 2)),0) * a + max((y - (i/ 2)),0) * b;
					}
			}
			cout << price_min;
		
}