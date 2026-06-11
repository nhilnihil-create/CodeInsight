#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define e "\n"
#define MaRiaMa { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
#define fix(n) cout << fixed << setprecision(n);
using namespace std;
int main()
{
	MaRiaMa;
	set<int> p;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		p.emplace(x);
	}
	cout << p.size();
}