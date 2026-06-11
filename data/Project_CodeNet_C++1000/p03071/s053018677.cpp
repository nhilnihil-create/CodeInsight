#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int ans1 = a + a - 1;
	int ans2 = b + b - 1;
	int ans3 = a + b;
	cout << fmax(fmax(ans1, ans2), ans3) << endl;
}
