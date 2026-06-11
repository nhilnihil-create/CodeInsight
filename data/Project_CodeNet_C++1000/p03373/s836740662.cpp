#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	c *= 2;
	cout << min(a+b,c)*min(x,y)+(x>y?min(a,c):min(b,c))*abs(x-y) << endl;
}

