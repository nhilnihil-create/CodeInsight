/*https://atcoder.jp/contests/abc108/tasks/abc108_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = c - a, y = d - b;
	cout << c - y << " " << d + x << " " << a - y << " " << b + x;

}