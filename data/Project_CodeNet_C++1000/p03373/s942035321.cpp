#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	int m = 2*c*max(x,y);
	m = min(m, a*x + b*y);
	m = min(m, a*x + 2*c*y);
	m = min(m, b*y + 2*c*x);
	if (x > y)
		m = min(m, 2*c*y + (x-y)*a);
	else 
		m = min(m, 2*c*x + (y-x)*b);
	cout << m << endl;
}

