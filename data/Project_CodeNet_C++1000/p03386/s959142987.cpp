#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n)
using namespace std;
int main()
{
	MaRiaMa;
	int a, b, k;
	set<int> p;
	cin >> a >> b >> k;
	int c = k, d = k;
	for (int i = a; i <= b; i++)
	{
		p.emplace(i);
		c--;
		if (c == 0)
			break;
	}
	for (int i = b; i >= a; i--)
	{
		p.emplace(i);
		d--;
		if (d == 0)
			break;
	}
	for (auto it = p.begin(); it != p.end(); it++)
	{
		cout << *it << e;
	}
}



