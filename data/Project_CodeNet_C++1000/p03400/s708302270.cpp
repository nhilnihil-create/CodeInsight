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
	int n, d, x, m = 0;
	int ar[100];
	cin >> n >> d >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++)
	{
		ll sum = 0;
		int k = 1;
		while (1)
		{
		    sum += ((k*ar[i]) + 1);
			if (sum <= d)
			{
				m++;
				k++;
				sum = 0;
			}
			else
			{
				break;
			}
			
		}
	}
	cout << m + x + n;
}



