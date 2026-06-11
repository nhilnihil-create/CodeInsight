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
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		if (s[i] == 'o')
			sum += 100;
	}
	
	cout << 700 + sum;
}


