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
	int k;
	int ar[3];
	cin >> ar[0] >> ar[1] >> ar[2] >> k;
	sort(ar, ar + 3, greater<int>());
	int s= ar[0]*pow(2, k);
	s += (ar[1] + ar[2]);
	cout << s;
}



