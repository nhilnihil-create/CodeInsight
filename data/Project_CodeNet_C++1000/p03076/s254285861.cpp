/*https://atcoder.jp/contests/abc123/tasks/abc123_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a[5];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	int count = 5, dish, total_t = 0;
	while (count--)
	{
		// count++;
		int min_time = 11, pos;
		for (int i = 0; i < 5; i++)
		{

			int time ;
			// if (a[i] != 0)

			if (a[i] % 10 == 0)
				time = a[i] % 10;
			else
				time = 10 - a[i] % 10;
			// cout << a[i] << " " << time << endl;

			if (min_time > time && a[i] > 0)
			{
				min_time = time;
				dish = a[i];
				pos = i;
			}
			// cout << min_time << " " << dish << endl;
			// cout << endl;
		}
		a[pos] = 0;
		// cout << min_time << " " << dish << endl;
		// cout << endl;
		total_t += dish;
		// cout << dish << " " << total_t << " ";

		if (total_t % 10 != 0 && count != 0)
			total_t += (10 - total_t % 10);
		// cout << total_t << endl;
	}
	cout << total_t;
}