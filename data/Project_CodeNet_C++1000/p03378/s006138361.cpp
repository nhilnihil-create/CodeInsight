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
	int n, m, x,k=0,l=0;
	cin >> n >> m >> x;
	int ar[100];
	set<int> p;
	while (m--)
	{
		int x;
		cin >> x;
		p.emplace(x);
	}
	for (int i = 0; i <= n; i++)
	{
		if (p.count(i) == 1)
			ar[i] = -1;
		else
			ar[i]=i;
	}
	for (int i=0;i<x;i++)
	{
		if (ar[i] == -1)
			k++;
	}
	for (int i = x+1; i <= n; i++)
	{
		if (ar[i] == -1)
			l++;
	}
	cout << min(k, l);
}



