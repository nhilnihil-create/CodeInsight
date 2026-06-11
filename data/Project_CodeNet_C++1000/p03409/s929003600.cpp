// AtCode.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdint.h>
#include <queue>

using namespace std;

typedef struct {
	int x = 0;
	int y = 0;
} Point;

typedef vector<Point> PointArray;

// 構造体vectorのソート方法を指定する関数
bool cmp_x_then_y(const Point& left, const Point& right) {
	if (left.x == right.x) return left.y < right.y;
	return left.x < right.x;
}

int main() {

	int N;
	cin >> N;	// ~100
	PointArray redPoints;
	for (int i = 0; i < N; i++) {
		Point tmp;
		cin >> tmp.x >> tmp.y;
		redPoints.push_back(tmp);
	}
	PointArray bluePoints;
	for (int i = 0; i < N; i++) {
		Point tmp;
		cin >> tmp.x >> tmp.y;
		bluePoints.push_back(tmp);
	}
	sort(redPoints.begin(), redPoints.end(), cmp_x_then_y);
	sort(bluePoints.begin(), bluePoints.end(), cmp_x_then_y);

	int count = 0;
	for (int i = 0; i < bluePoints.size(); i++) {
		// 青い点のx座標が小さい側からマッチングする点を探してゆく
		Point &blue = bluePoints[i];
		int match_id = -1;
		int max_y = -1;
		for (int j = 0; j < redPoints.size(); j++) {
			if ((redPoints[j].x < blue.x) && (redPoints[j].y < blue.y)) {
				if (max_y < redPoints[j].y) {
					match_id = j;
					max_y = redPoints[j].y;
				}
			}
			else if(redPoints[j].x >= blue.x) {
				break;
			}
		}
		if (match_id != -1) {
			count++;
			redPoints.erase(redPoints.begin() + match_id, redPoints.begin() + match_id + 1);
		}
	}
	cout << count << endl;

	return 0;

}

/*
5
4 8 *
7 3 **
1 6 ***
2 2
0 0

6 9 *
9 1
8 5 **
3 7 ***
5 4

*/