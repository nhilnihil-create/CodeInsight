#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
	bool used;
};


bool xsmaller(const point& a, const point& b)
{
	return a.x < b.x;
}

bool ygrater(const point& a, const point& b)
{
	return a.y > b.y;
}


int main(void) {
	int N;
	cin >> N;
	vector <point> red(N), blue(N);
	for (int i = 0; i < N; i++) {
		cin >> red[i].x >> red[i].y;
		red[i].used = false;
	}
	for (int i = 0; i < N; i++) {
		cin >> blue[i].x >> blue[i].y;
	}
	sort(red.begin(), red.end(), xsmaller);
	sort(blue.begin(), blue.end(), xsmaller);

	int ans = 0;
	int xpos = 0;
	for (int i = 0; i < N; i++) {
		int x = blue[i].x;
		int y = blue[i].y;
		for (; xpos < N; xpos++) {
			if (red[xpos].x < x) continue;
			else break;
		}
		sort(red.begin(), red.begin()+xpos, ygrater);
		for (int j = 0; j < xpos; j++) {
			if (red[j].used) continue;
			if (red[j].y < y) {
				ans++;
				red[j].used = true;
				break;
			}
		}
	}
	cout << ans << endl;
  return 0;
}
