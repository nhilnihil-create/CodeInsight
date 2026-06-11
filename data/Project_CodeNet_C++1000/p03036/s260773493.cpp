#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int r, D, x2000;
	cin >> r >> D >> x2000;

	for (int i = 2001; i <= 2010; i++) {
		x2000 = r * x2000 - D;
		cout << x2000 << endl;
	}
}
