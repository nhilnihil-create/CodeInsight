#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, K;
	string An;
	cin >> N >> K;
	cin >> An;

	int ans = 0;
	while (N > 0)
	{
		++ans;
		if (N <= K)
			N = 0;
		else
			N -= (K - 1);
	}
	cout << ans << endl;
	return 0;
}

