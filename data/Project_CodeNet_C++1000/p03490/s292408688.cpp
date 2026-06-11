#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <set>

std::vector<int> X, Y;
std::string input;

std::set<int> resultX[2], resultY[2];

int main(void) {
	std::cin >> input;
	int start_x = 0, finish_x, finish_y;
	bool flag = true, XY = true;
	
	scanf("%d %d", &finish_x, &finish_y);

	int f = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == 'T') {
			flag = false;
			if (XY) {
				XY = false;
				X.push_back(f);
			}
			else {
				XY = true;
				Y.push_back(f);
			}
			f = 0;
			continue;
		}

		if (flag)
			start_x++;
		else
			f++;
	}

	if (f != 0 && XY)
		X.push_back(f);
	else if (f != 0 && !XY)
		Y.push_back(f);

	resultX[0].insert(start_x);
	resultY[0].insert(0);

	for (int i = 0; i < X.size(); i++) {
		int cur = (i % 2), next = (i + 1) % 2;

		for (auto it = resultX[cur].begin(); it != resultX[cur].end(); it++) {
			int val1 = *it + X[i], val2 = *it - X[i];
			if (val1 <= 8000)
				resultX[next].insert(val1);
			if (val1 >= -8000)
				resultX[next].insert(val2);
		}
		resultX[cur].clear();
	}

	for (int i = 0; i < Y.size(); i++) {
		int cur = (i % 2), next = (i + 1) % 2;

		for (auto it = resultY[cur].begin(); it != resultY[cur].end(); it++) {
			int val1 = *it + Y[i], val2 = *it - Y[i];
			if (val1 <= 8000)
				resultY[next].insert(val1);
			if (val2 >= -8000)
				resultY[next].insert(val2);
		}
		resultY[cur].clear();
	}

	int curX = X.size() % 2, curY = Y.size() % 2;

	if (resultX[curX].find(finish_x) != resultX[curX].end() && resultY[curY].find(finish_y) != resultY[curY].end())
		printf("Yes\n");
	else
		printf("No\n");
}