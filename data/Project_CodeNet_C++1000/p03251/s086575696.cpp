#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_1_dimensional_world_tale(void) {
	int X, n, Y, m;
	int x[110];
	int y[110];

	string judge = "No War";

	cin >> n >> m >> X >> Y;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < m; i++) cin >> y[i];

	x[n] = X;
	y[m] = Y;

	sort(x, x + n+1);
	sort(y, y + m+1);

	//if (X > Y) {
	//	judge = "War";
	//}

	if (y[0]-x[n]<1) {
		judge = "War";
	}
	

	cout << judge << endl;
}

int main()
{
	b_1_dimensional_world_tale();
    return 0;
}