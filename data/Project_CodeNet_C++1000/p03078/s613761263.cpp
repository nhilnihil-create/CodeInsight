// Cake 123.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long X[1001], Y[1001], Z[1001];
int main()
{
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	for (int i = 0; i != x; i++)
	{
		cin >> X[i];
	}
	for (int i = 0; i != y; i++)
	{
		cin >> Y[i];
	}
	for (int i = 0; i != z; i++)
	{
		cin >> Z[i];
	}
	sort(X, X + x, greater<long long>());
	sort(Y, Y + y, greater<long long>());
	sort(Z, Z + z, greater<long long>());
	int xn = 1, yn = 1, zn = 1;
	while (xn * yn * zn < k)
	{
		if (xn < x)xn++;
		if (yn < y)yn++;
		if (zn < z)zn++;
	}
	vector<long long> v;
	for (int xi = 0; xi < xn; xi++)
	{
		for (int yi = 0; yi < yn; yi++)
		{
			for (int zi = 0; zi < zn; zi++)
			{
				v.push_back((long long)X[xi] + Y[yi] + Z[zi]);
			}
		}
	}
	long long minimum = (long long)X[xn - 1] + Y[yn - 1] + Z[zn - 1];
	for (int xi = 0; xi < xn; xi++)
	{
		for (int yi = 0; yi < yn; yi++)
		{
			for (int zi = zn; zi < z; zi++)
			{
				long long res = (long long)X[xi] + Y[yi] + Z[zi];
				if (res > minimum)
					v.push_back((long long)X[xi] + Y[yi] + Z[zi]);
			}
		}
	}
	for (int xi = 0; xi < xn; xi++)
	{
		for (int yi = yn; yi < y; yi++)
		{
			for (int zi = 0; zi < zn; zi++)
			{
				long long res = (long long)X[xi] + Y[yi] + Z[zi];
				if (res > minimum)
					v.push_back((long long)X[xi] + Y[yi] + Z[zi]);
			}
		}
	}
	for (int xi = xn; xi < x; xi++)
	{
		for (int yi = 0; yi < yn; yi++)
		{
			for (int zi = 0; zi < zn; zi++)
			{
				long long res = (long long)X[xi] + Y[yi] + Z[zi];
				if (res > minimum)
					v.push_back((long long)X[xi] + Y[yi] + Z[zi]);
			}
		}
	}
	for (int xi = 0; xi < xn; xi++)
	{
		for (int yi = yn; yi < y; yi++)
		{
			for (int zi = zn; zi < z; zi++)
			{
				long long res = (long long)X[xi] + Y[yi] + Z[zi];
				if (res > minimum)
					v.push_back((long long)X[xi] + Y[yi] + Z[zi]);
			}
		}
	}
	for (int xi = xn; xi < x; xi++)
	{
		for (int yi = 0; yi < yn; yi++)
		{
			for (int zi = zn; zi < z; zi++)
			{
				long long res = (long long)X[xi] + Y[yi] + Z[zi];
				if (res > minimum)
					v.push_back((long long)X[xi] + Y[yi] + Z[zi]);
			}
		}
	}
	for (int xi = xn; xi < x; xi++)
	{
		for (int yi = yn; yi < y; yi++)
		{
			for (int zi = 0; zi < zn; zi++)
			{
				long long res = (long long)X[xi] + Y[yi] + Z[zi];
				if (res > minimum)
					v.push_back((long long)X[xi] + Y[yi] + Z[zi]);
			}
		}
	}
	sort(v.begin(), v.end(), greater<long long>());
	for (int i = 0; i < k; i++)
	{
		cout << v[i] << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
