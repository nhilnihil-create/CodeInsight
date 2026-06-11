#include<bits/stdc++.h>
using namespace std;
void c_p_c()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef  ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int main()
{
//	c_p_c();
	int a, b;
	cin >> a >> b;
	int p = a * b;
	if (p & 1)
		cout << "Odd";
	else
		cout << "Even";
	//cout << ((a * b) & 1) ? "Odd" : "Even";
}