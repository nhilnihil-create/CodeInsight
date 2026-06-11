#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int a, b, c, d,x,y;
	cin >> a >> b >> c >> d;
	x = a + b;
	y = c + d;
	if (x > y) {
		cout << "Left" << endl;
	}
	else if(y > x) {
		cout << "Right" << endl;
	}
	else {
		cout << "Balanced" << endl;
	}
	return 0;
}