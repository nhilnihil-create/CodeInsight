#define _USE_MATH_DEFINES
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<queue>
#include<stdbool.h>
#include<math.h>
#include<sstream>
typedef long long ll;
#define N (1000000000+7)
using namespace std;
typedef pair<int, int> P;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	int n, ma = -10000000, mi = 10000000, minindex = 0, maxindex = 0;
	cin >> n;
	vector<int>a(n + 1);
	vector<stringstream>s(2 * n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (a[i] > ma) {
			ma = a[i];
			maxindex = i;
		}
		if (a[i] < mi) {
			mi = a[i];
			minindex = i;
		}
	}
	//最小値と最大値が同じ、つまり全部同じ
	if (ma == mi) {
		cout << 0 << endl;
		return 0;
	}
	//全て正の時,最大値を一番初めに足せばあとは順にやればいい
	if (mi >= 0) {
		int count = 0;
		int index = 0;
		while (true) {
			if (index == n)break;
			while (a[index] > a[index + 1]) {
				a[index + 1] += ma;
				count++;
				s[count] << maxindex << " " << index + 1;
			}
			index++;
			if (ma < a[index]) {
				ma = a[index];
				maxindex = index;
			}
		}
		cout << count << endl;
		for (int i = 1;i <= count;i++)cout << s[i].str() << endl;
		return 0;
	}

	if (ma <= 0) {
		int count = 0;
		int index = n;
		while (true) {
			if (index == 1)break;
			while (a[index] < a[index - 1]) {
				a[index - 1] += mi;
				count++;
				s[count] << minindex << " " << index - 1;
			}
			index--;
			if (mi > a[index]) {
				mi = a[index];
				minindex = index;
			}
		}
		cout << count << endl;
		for (int i = 1;i <= count;i++)cout << s[i].str() << endl;
		return 0;
	}
	
	if (ma < abs(mi)) {
		int index = 1, count = 0;
		while (true) {
			if (index == n + 1)break;
			while (a[index] >= 0) {
				a[index] += mi;
				count++;
				s[count] << minindex << " " << index;
			}
			index++;
		}
		index = n;
		while (true) {
			if (index == 1)break;
			while (a[index] < a[index - 1]) {
				a[index - 1] += mi;
				count++;
				s[count] << minindex << " " << index - 1;
			}
			index--;
			if (mi > a[index]) {
				mi = a[index];
				minindex = index;
			}
		}
		cout << count << endl;
		for (int i = 1;i <= count;i++)cout << s[i].str() << endl;
		return 0;
	}
	int index = 1, count = 0;
	while (true) {
		if (index == n + 1)break;
		while (a[index] <= 0) {
			a[index] += ma;
			count++;
			s[count] << maxindex << " " << index;
		}
		index++;
	}
	index = 1;
	while (true) {
		if (index == n)break;
		while (a[index] > a[index + 1]) {
			a[index + 1] += ma;
			count++;
			s[count] << maxindex << " " << index + 1;
		}
		index++;
		if (a[index] > ma) {
			ma = a[index];
			maxindex = index;
		}
	}
	cout << count << endl;
	for (int i = 1;i <= count;i++)cout << s[i].str() << endl;
	return 0;
}