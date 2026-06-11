#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int N, H, W;
	cin >> N >> H >> W;
	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		int A, B;
		cin >> A >> B;
		if (H <= A && W <= B)
		{
			++ans;
		}
	}
	cout << ans << endl;
}

int main()
{
	solve();
	return(0);
}