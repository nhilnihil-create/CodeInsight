#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int ls1[Max], ls2[Max];
int n;


int main()
{
	int n;
	cin >> n;
	map<int,int> ma;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		if (ma[t]) continue;
		ma[t]++;
		sum++;
	}
	cout << sum;
}