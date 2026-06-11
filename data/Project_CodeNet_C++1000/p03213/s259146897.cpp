#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;
int a[105];


int main() {
	int n;
	
	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		int u = i;
		for (int j = 2; j < n + 1; j++) {
			while (u % j == 0) {
				u /= j;
				a[j]++;
			}
		}
	}
	int cou2 = 0;
	int cou4 = 0;
	for (int i = 0; i < n + 1; i++) {
		if (a[i]<4&&a[i] >= 2)cou2++;
		if (a[i] >= 4)cou4++;
	}
	int ans = cou2 * cou4 * (cou4 - 1) / 2 + cou4 * (cou4 - 1) * (cou4 - 2)/2 ;
	int cou14 = 0;
	cou4 = 0;
	for (int i = 0; i < n + 1; i++) {
		if (a[i] < 14 && a[i] >= 4)cou4++;
		if (a[i] >= 14)cou14++;
	}
	ans += cou14 * cou4+cou14*(cou14-1);
	int cou24 = 0;
	cou2 = 0;
	for (int i = 0; i < n + 1; i++) {
		if (a[i] < 24 && a[i] >= 2)cou2++;
		if (a[i] >= 24)cou24++;
	}
	ans += cou24 * cou2 + cou24 * (cou24 - 1);
	int cou = 0;
	for (int i = 0; i < n + 1; i++) {
		if (a[i] >=74)cou++;
	}
	ans += cou;
	cout << ans;
}