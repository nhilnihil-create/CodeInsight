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
	int n=0;
	ll al = 0, bu = 0;
	cin >> n;
	int p[100];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	sort(p, p+n, greater<int>());
	for (int i = 0; i < n; i++)
	{
		if(i%2==0)
		al += p[i];
		else
		bu += p[i];
	}
	
	cout << al-bu;
}



