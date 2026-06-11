#include <iostream>
using namespace std;

int main() {
	int n, h, w;
	scanf("%d%d%d", &n, &h, &w);
	int cnt = 0;
	while (n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= h && y >= w)
			cnt++;
	}

	cout << cnt << endl;
	
	return 0;
}