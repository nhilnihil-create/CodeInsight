#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;

int lst[Max];
int sum[Max];


int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	int l = 0;
	for (int i = 1;i <= m;i++)
	{
		int t;
		scanf("%d", &t);
		for (int j = l;j <= t-1;j++)
		{
			sum[j+1] = sum[j];
		}
		sum[t]++;
		l = t;
	}
	cout << min(sum[x - 1], sum[l] - sum[x]);

		
}