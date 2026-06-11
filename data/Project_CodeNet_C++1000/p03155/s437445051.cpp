#include <iostream>

using namespace std;

void solve()
{
	int N, H, W;
	cin >> N;
	cin >> H;
	cin >> W;
	cout << (N - H + 1) * (N - W + 1) << endl;
}

int main()
{
	solve();
	return(0);
}