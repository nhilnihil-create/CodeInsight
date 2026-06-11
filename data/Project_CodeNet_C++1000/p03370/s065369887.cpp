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
	int n, d;
	ll sum = 0;
	cin >> n >> d;
	int ar[100];
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
		sum += ar[i];
	}
	d -= sum;
	int k = d / *min_element(ar, ar + n);
	cout << n + k;
/* 999*/
}