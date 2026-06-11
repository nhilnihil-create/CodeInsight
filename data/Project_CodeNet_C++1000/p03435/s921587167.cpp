#include<bits/stdc++.h>
using namespace std;

int main()
{
	int C[3][3];
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> C[i][j];
	int ok = 1;
	if (C[0][0] - C[1][0] != C[0][1] - C[1][1]) ok = 0;
	if (C[0][0] - C[1][0] != C[0][2] - C[1][2]) ok = 0;
	if (C[0][0] - C[2][0] != C[0][1] - C[2][1]) ok = 0;
	if (C[0][0] - C[2][0] != C[0][2] - C[2][2]) ok = 0;
	cout << (ok ? "Yes" : "No") << endl;
}

