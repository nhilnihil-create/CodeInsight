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
	int a, b, x;
	cin >> a >> b >> x;
	if (((a -x) <= 0)&&(x-a)-b<=0)
		cout << "YES";
	else
		cout << "NO";
}


