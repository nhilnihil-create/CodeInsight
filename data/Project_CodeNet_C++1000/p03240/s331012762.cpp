#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int(*heights)[100] = new int[100][100];
	int xs[100];
	int ys[100];
	int x, y, h;
	int k = 0;
	while (cin >> x >> y >> h)
	{
		xs[k] = x;
		ys[k++] = y;
		heights[x][y] = h;
	}

	long long int H = 1;
	long long int max_H = 1000000000 + 201;
	int i = 0;
	int Cx = 0;
	int Cy = 0;
	for (Cx = 0; i < N && Cx <= 100; Cx++)
		for (Cy = 0; i < N && Cy <= 100; Cy++)
		{
			long long int temp_H = 0; //作为测试标杆，如果对于每一对坐标，H都与temp_H相等，则说明H正确。
			for (i = 0; i < N; i++)
			{
				if (heights[xs[i]][ys[i]] > 0)
				{
					H = abs(xs[i] - Cx) + abs(ys[i] - Cy) + heights[xs[i]][ys[i]];
					if (temp_H == 0)
						temp_H = H;
					if (H != temp_H || H > max_H)
						break;
				}
				else
				{
					max_H = abs(xs[i] - Cx) + abs(ys[i] - Cy) + heights[xs[i]][ys[i]];
					if (temp_H > max_H)
						break;
				}
			}

		}
	delete[] heights;
	cout << Cx - 1 << ' ' << Cy - 1 << ' ' << H;
}
