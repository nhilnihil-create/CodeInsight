#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int main()
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int X = x2 - x1;
	int Y = y2 - y1;

	int x3 = x2 - Y;
	int y3 = y2 + X;
	int x4 = x3 - X;
	int y4 = y3 - Y;


	cout << x3<<" "<<y3<<" "<<x4<<" "<<y4 << endl;

	return 0;


}

