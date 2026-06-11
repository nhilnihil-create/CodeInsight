#include <iostream>
using namespace std;

int main() {
	int a, b;
 	cin >> a >> b;
  	int res = -100000;
  	res = max(res, a+b);
  	res = max(res, a-b);
  	res = max(res, a*b);
  	cout << res << endl;
  	return 0;
}
