#include <iostream>
#include <cmath>
using namespace std;
struct cordinate
{
	long long x;
	long long y;
	long long h;
};

int main()
{
	long long N;
	int flag = 0;
	cin >> N;
	cordinate* ip;
	ip = new cordinate[N];
	for (int i = 0;i < N;i++)
	{
		cin >> ip[i].x >> ip[i].y >> ip[i].h;
	}
	long long i, j, k;
	for (i = 0;i < N && ip[i].h == 0;i++);

	long long a = ip[i].x, b = ip[i].y;
	long long c = ip[i].h;
	

	for (i = 0;i <= 100;i++)
	{
		for (j = 0; j <= 100;j++)
		{
			flag = 1;
			for (k = 0;k < N;)
			{
				if (ip[k].h == 0)
				{
					if (abs(i - ip[k].x) + abs(j - ip[k].y) - abs(i - a) - abs(j - b) >= c)
					{
						k++;
						continue;
					}
					else
					{
						flag = 0;
						break;
					}
				}
				if ((abs(i - ip[k].x) + abs(j - ip[k].y) - (abs(i - a) + abs(j - b))) != c - ip[k].h)
				{
				flag = 0;
				break;
				}
				k++;
			}
			if (flag == 1) break;
		}
		if (flag == 1) break;
	}
	cout << i << ' ' << j << ' ' << abs(i - a) + abs(j - b) + c;
	delete[]ip;
}