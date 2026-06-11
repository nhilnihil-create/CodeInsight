#include<iostream>
#include<vector>

using namespace std;

class Point {
public:
	int x;
	int y;
	int h;
	Point(int a, int b, int c) {
		x = a;
		y = b;
		h = c;
	}
};


int main() {
	int i = 0, j, h, N, c;
	int xi, yi, hi;
	cin >> N;
	vector<Point> pts;
	int max_h = 0;//所有坐标中的最大高度
	for (; i < N; ++i) {
		cin >> xi >> yi >> hi;
		if (hi > max_h) 
			max_h = hi;

		Point r(xi, yi, hi);
		pts.push_back(r);
	}
	int flag = 0;
	int c_h;
	for (i = 0; (i <= 100)&&(flag ==0); ++i) { //给定横坐标i
		for (j = 0; (j <= 100)&&(flag ==0); ++j) { //给定纵坐标j
			for (h = max_h; h <= max_h+200; ++h) { //给定高度h
				for (c = 0; c < N; ++c) { //检查每个坐标是否符合给定条件
					c_h = h - abs(pts[c].x - i) - abs(pts[c].y - j);
					if (pts[c].h == c_h)  ++flag;
					else if ((pts[c].h == 0) && c_h < 0)  ++flag;
					else break;
				}
				if (flag != N) flag = 0;
				else break;
			}
		}
	}
	cout << i - 1 << ' ' << j - 1 << ' ' << h;
	return 0;
}