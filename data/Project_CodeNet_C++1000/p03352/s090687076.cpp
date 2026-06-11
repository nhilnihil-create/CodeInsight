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
	set<int> p;
	int n;
	cin >> n;
	if (n == 1 || n == 2 || n == 3)
		cout << "1";
	else
	{
		for (int i = 2; i < n; i++)
		{
			int k = 2;
			while (1)
			{
				int u = pow(i, k);
				if (u > n)
				{
					break;
				}
				p.emplace(u);
				k++;
			}
		}
		auto it = p.rbegin();
		cout << *it;
	}
	//**11**11**//	
}