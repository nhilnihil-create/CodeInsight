#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_grid_repating2(void) {
	int h, w;
	char s[51][51];
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cin >> s[i][j];
	}

	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			char org = s[j][i];
			char org_xp1;
			char org_xm1;
			char org_yp1;
			char org_ym1;
			if (org == '#') {
				if (i == 0) org_xm1 = '.';
				else        org_xm1 = s[j][i - 1];

				if (i == w - 1) org_xp1 = '.';
				else            org_xp1 = s[j][i + 1];

				if (j == 0) org_ym1 = '.';
				else        org_ym1 = s[j - 1][i];

				if (j == h - 1) org_yp1 = '.';
				else            org_yp1 = s[j + 1][i];

				if ((org_xm1 == '#') || (org_xp1 == '#') || (org_ym1 == '#') || (org_yp1 == '#')) continue;

				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
}

int main()
{
    c_grid_repating2();
    return 0;
}