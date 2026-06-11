#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;

int lst[Max];
string ls[Max];
map<string, int> ma1, ma2;

int main()
{
	int n, d, x;
	cin >> n >> d >> x;
	ll res = x;
	for (int i = 1;i <= n;i++)
	{
		int t;
		scanf("%d", &t);
		res += (1 + (d - 1) / t);
	}
	cout << res;
}