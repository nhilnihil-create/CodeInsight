#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
 
using namespace std;
 
 
 
int main() {
	
	int h, w;
	cin >> h >> w;
 
	vector<string> s(50);
 
	for (int i = 0; i < h; i++) {
		cin >> s.at(i);
	}
 
	vector<int> x{ 1, 0, -1, 1, 0, -1, 1, -1 };
	vector<int> y{ 1, 1, 1, -1, -1, -1, 0, 0 };
 
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s.at(i).at(j) == '#') continue;
 
			int dx;
			int dy;
			int num = 0;
			for (int k = 0; k < 8; k++) {
				dx = x.at(k);
				dy = y.at(k);
 
 
				int a = i + dx;
				int b = j + dy;
 
				if (a >= h || a < 0) continue;
				if (b >= w || b < 0) continue;
				if (s.at(a).at(b) == '#') ++num;
			}
			s.at(i).at(j) = num + '0';
		}
	}
 
	for (int i = 0; i < h; i++) {
		cout << s.at(i) << endl;
	}
 
	return 0;
}
