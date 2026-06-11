#include <iostream>
using namespace std;
typedef int I;
I main() { 
	I n, c = 0,l[100]; cin >> n; 
	bool f = false;
	for (I i = 0; i < n; i++) { 
		I m;
		cin >> m; 
		l[i] = m;
		i > 0 ? ((l[i - 1] == l[i] && f==false) ? (c++, f=true): f=false) : 0 ; 
	} 
	cout << c << endl;
}