#include <iostream>
using namespace std;

int N, Q;
char s[200000],t[200000],d[200000];


int BS1(int min, int max)
{
	if (max - min > 1) 
	{
		int check = 0;
		int mid = min + (max - min) / 2;
		int tmp = mid;
		for (int i = 0; i < Q; i++)
		{
			if (s[tmp] == t[i])
			{
				if (d[i] == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1)
			{
				check++;
				break;
			}
			if (tmp == N)
			{
				break;
			}
		}

		if (check == 0)
		{
			return BS1(min, mid);
		}
		else
		{
			return BS1(mid, max);
		}
	}
	else
	{
		int check1 = 0;
		int tmp = min;
		for (int i = 0; i < Q; i++)
		{
			if (s[tmp] == t[i])
			{
				if (d[i] == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1)
			{
				check1++;
				break;
			}
			if (tmp == N)
			{
				break;
			}
		}

		int check2 = 0;
		tmp = max;
		for (int i = 0; i < Q; i++)
		{
			if (s[tmp] == t[i])
			{
				if (d[i] == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1)
			{
				check2++;
				break;
			}
			if (tmp == N)
			{
				break;
			}
		}

		if (check2 == 1)
			return max;
		else if (check1 == 1)
			return min;
		else
			return min - 1;
	}
}

int BS2(int min, int max)
{
	if (max - min > 1)
	{
		int check = 0;
		int mid = min + (max - min) / 2;
		int tmp = mid;
		for (int i = 0; i < Q; i++)
		{
			if (s[tmp] == t[i])
			{
				if (d[i] == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1)
			{
				break;
			}
			if (tmp == N)
			{
				check++;
				break;
			}
		}

		if (check == 0)
		{
			return BS2(mid, max);
		}
		else
		{
			return BS2(min, mid);
		}
	}
	else
	{
		int check1 = 0;
		int tmp = min;
		for (int i = 0; i < Q; i++)
		{
			if (s[tmp] == t[i])
			{
				if (d[i] == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1)
			{
				break;
			}
			if (tmp == N)
			{
				check1++;
				break;
			}
		}

		tmp = max;
		int check2 = 0;
		for (int i = 0; i < Q; i++)
		{
			if (s[tmp] == t[i])
			{
				if (d[i] == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1)
			{
				break;
			}
			if (tmp == N)
			{
				check2++;
				break;
			}
		}

		if (check1 == 1)
			return min;
		else if (check2 == 1)
			return max;
		else
			return max + 1;
	}
}

int main()
{
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> s[i];

	for (int i = 0; i < Q; i++)
		cin >> t[i] >> d[i];


	int a = BS1(0, N - 1);
	int b = BS2(0, N - 1);

	cout << b - a - 1;

	return 0;

}