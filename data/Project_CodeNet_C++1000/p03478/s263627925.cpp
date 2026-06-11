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
	int n, a, b;
	cin >> n >> a >> b;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = i;
		int s = 0;
		while (t > 0)
		{
			s += t % 10;
			t /= 10;
		}
		if (s <= b && s >= a) sum += i;
	}
	cout << sum;
}