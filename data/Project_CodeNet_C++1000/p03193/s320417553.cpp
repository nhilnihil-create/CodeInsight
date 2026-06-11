#include <iostream>
using namespace std;

int A, B, N, H, W;
int main()
{
	cin >> N >> H >> W;
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A >> B;
		if (A >= H && B >= W)
			ans++;
	}
	cout << ans << endl;
	return 0;
}