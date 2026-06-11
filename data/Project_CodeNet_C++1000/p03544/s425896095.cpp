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
	ll n;
	ll p[1000];
	p[0]= 2;
	p[1]= 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		p[i] = (p[i - 2] + p[i - 1]);
	}
	cout << p[n];
}