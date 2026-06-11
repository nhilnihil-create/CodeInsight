#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int		main()
{
	int A,B,C,X;
	cin >> A >> B >> C >> X;
	int h = 0,i, count = 0;
	while (h <= A)
	{
		i = 0;
		while (i <= B)
		{
			if ((X - 500 * h - 100 * i) / 50 <= C && (X - 500 * h - 100 * i) % 50 == 0
			&& (X - 500 * h - 100 * i) >= 0)
				count++;
			i++;
		}
		h++;
	}
	cout << count << endl;
}