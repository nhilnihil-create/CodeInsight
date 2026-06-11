#include <iostream>
using namespace std;

int main()
{
	int N;

	cin >> N;

	int t,bt,dt,bx,x,dx,by,y,dy;
	bt = bx = by = 0;

	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		dt = t - bt;
		dx = abs(x - bx);
		dy = abs(y - by);
		if (dx + dy - dt > 0) {
			cout << "No" << endl;
			return 0;
		} else if ((dt - (dx + dy)) % 2 == 1) {
			cout << "No" << endl;
			return 0;
		}
		bt = t;
		bx = x;
		by = y;
	}
	cout << "Yes" << endl;
}