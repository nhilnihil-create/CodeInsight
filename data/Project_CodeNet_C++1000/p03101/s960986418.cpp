#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d,e,f,g;
	cin >> a >> b >> c >> d;
	e = a * b;
	f = a - c;
	g = b * c;
	if (a*b == c * d) {
		cout << 0 << endl;
	}
	
	else {
		cout << e - (g + f*d) << endl;
	}
}