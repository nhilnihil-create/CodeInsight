#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int lst[Max], ls[Max];
int n;

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	map<char, int> ma;
	for (int i = 1; i <= n; i++)
	{
		char t;
		cin >> t;
		if (ma[t]) continue;
		else
		{
			ma[t]++;
			sum++;
		}
	}
	if (sum == 4) cout << "Four";
	else cout << "Three";
	 

}