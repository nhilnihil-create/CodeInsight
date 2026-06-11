#include <iostream>
using namespace std;

int main()
{
	int N, d[100],k=1;
	cin >> N; for (int i = 0; i < N; i++) cin >> d[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; i < j; j--)
		{
			if (d[j - 1] > d[j]) swap(d[j - 1], d[j]);
		}
	}
	for (int i = 0; i < N-1; i++) if (d[i] != d[i + 1]) k++;
	cout << k;
}