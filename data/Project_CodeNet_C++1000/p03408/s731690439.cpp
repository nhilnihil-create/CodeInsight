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
	int n=0, m=0;
	cin >> n;
	int ar[100];
	vector<string>b(100);
	vector<string>r(100);
	multiset<string> bl; multiset<string> re;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		bl.emplace(b[i]);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> r[i];
		re.emplace(r[i]);
	}
	for (int i = 0; i <n; i++)
	{
		ar[i] = bl.count(b[i]) - re.count(b[i]);
	}
	if (*max_element(ar, ar + n) < 0)
		cout << "0";
	else
		cout << *max_element(ar, ar + n);
}



