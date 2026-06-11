#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	int A;

	cin >> N;
	cin >> A;

	string ans = "No";

	for (int i = 0; i <= A; i++)
	{
		if ((N - i) % 500 == 0)
		{
			ans = "Yes";
			break;
		}
	}

	cout << ans << endl;
}