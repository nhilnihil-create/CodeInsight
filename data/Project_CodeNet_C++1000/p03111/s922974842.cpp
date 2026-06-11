#include <bits/stdc++.h>
using namespace std;
long long mypow(long long x, long long y)
{
	long long result = 1;
	while (y != 0) {
		if (y%2 != 0) {
			result *= x;
			y -= 1;
		}	
		x *= x;
		y /= 2;
	}
	return result;
}
int main(void)
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int l[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	int mp = 1e8;
	for (uint32_t i = 0; i < mypow(2, 2*n); i++) {
		int tmp = 0;
		int tmpa = 0, tmpb = 0, tmpc = 0;
		for (int j = 0; j < 2*n; j+=2) {
			int f = ((i>>j)&3);
			if (f == 0) {
				if (tmpa != 0)
					tmp += 10;
				tmpa += l[j/2];
			} else if (f == 1) {
				if (tmpb != 0)
					tmp += 10;
				tmpb += l[j/2];
			} else if (f == 2) {
				if (tmpc != 0)
					tmp += 10;
				tmpc += l[j/2];
			} else if (f== 3) {
			}
		}
		if (tmpa != 0 && tmpb != 0 && tmpc != 0) {
			mp = min(mp, tmp+abs(tmpa-a)+abs(tmpb-b)+abs(tmpc-c));
		}
	}
	cout << mp << endl;

	return 0;
}