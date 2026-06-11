#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int a, b;
	cin >> a >> b;
	cout << ((a+b == 15) ? "+" : (a*b == 15) ? "*" : "x") << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
