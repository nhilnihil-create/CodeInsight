#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, count=1, i = 0;
	cin >> N;
	int d[100];
	while (i < N)
		cin >> d[i++];
	sort (d, d+N);
	i = 0;
	while (i < N - 1)
	{
		if (d[i] < d[i+1])
			count++;
		i++;
	}
	cout << count << endl;
}