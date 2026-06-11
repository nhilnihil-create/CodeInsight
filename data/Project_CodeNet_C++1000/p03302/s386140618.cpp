#include <bits/stdc++.h>

using namespace std;



void hawawa()
{
	int a, b;
	cin >> a >> b;
	if (a * b == 15) {
		cout << "*\n";
	}else if(a + b == 15) {
		cout << "+\n";
	}
	else {
		cout << "x\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
	return 0;
}
