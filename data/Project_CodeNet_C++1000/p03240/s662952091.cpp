#include <iostream>
using namespace std;
struct point {
	int xi;
	int yi;
	int hi;
};
bool judge(int a, int b) {
	if (a == b || (a <= 0 && b == 0)) {
		return true;
	}
	else return false;
}
int main() {
	int H;
	int n,count, temp,t=0;
	cin >> n;
	point points[102];
	for (int i = 0; i < n; i++) {
		cin >> points[i].xi >> points[i].yi >> points[i].hi;
		if (points[i].hi != 0) t = i;
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {

			H = points[t].hi + abs(i-points[t].xi) +abs(j-points[t].yi);
			count = 0;
			for (int k = 0; k < n; k++) {
				temp = H-(abs(i - points[k].xi) + abs(j - points[k].yi));
				if (!judge(temp,points[k].hi) )break;
				if (count == n - 1) {
					cout << i << " " << j << " " << H << endl;
					return 0;
				}
				count++;
			}
		}
	}
	return 0;
}

