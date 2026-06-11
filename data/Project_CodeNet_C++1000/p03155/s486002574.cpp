#include <iostream>

using namespace std;

int main()
{
	int n, h, w;
	cin >> n >> h >> w;
	h--;
	w--;
	int ans = (n - h) * (n - w);
	cout << ans << endl;

	return 0;
}