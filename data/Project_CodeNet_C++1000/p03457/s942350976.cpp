#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 5;
int lst[Max];
int ls[Max];

int main()
{
	int n;
	cin >> n;
	int x = 0, y = 0;
	int t = 0;
	for (int i = 1;i <= n;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (abs(b - x) + abs(c - y) > a-t)
		{
			cout << "No" << endl;
			return 0;
		}
		else
		{
			if (-(abs(b - x) + abs(c - y) + (a-t)) % 2 != 0)
			{
				cout << "No";
				return 0;
			}
		}
		t = a;x = b;y = c;
	}
	cout << "Yes";
}