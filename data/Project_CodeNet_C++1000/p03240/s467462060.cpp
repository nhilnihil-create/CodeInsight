#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

int main(void)
{
	long h[100][3];
	long i, j, t, k, r=1, N, p;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> h[i][0];
		cin >> h[i][1];
		cin >> h[i][2];
		if (h[i][2] != long(0))
			p = i;
	}
	for (i = 0; i < 101; i++)
	{
		for (j = 0; j < 101; j++)
		{
			t = h[p][2] + abs(i - h[p][0]) + abs(j - h[p][1]);
			for (k = 0; k < N; k++)
			{
				if (max(t - abs(i - h[k][0]) - abs(j - h[k][1]), long(0)) != h[k][2])
				{
					r = 0;
					break;
				}
				r = 1;
			}
			if (r == 1)
				break;
		}
		if (r == 1)
			break;
	}
	cout << i << " " << j << " " << t << endl;
}