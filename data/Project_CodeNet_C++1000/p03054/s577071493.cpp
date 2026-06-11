#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int H, W, N;
	cin >> H >> W >> N;

	int SR, SC;
	cin >> SR >> SC;

	string S, T;
	cin >> S >> T;

	vector<char> dirs(4);
	dirs[0] = 'U', dirs[1] = 'R', dirs[2] = 'D', dirs[3] = 'L';

	vector<char> dirt(4);
	dirt[0] = 'D', dirt[1] = 'L', dirt[2] = 'U', dirt[3] = 'R';

	bool flag = false;
	for (int j = 0; j < 4 && !flag ; j++) {
		int sr = SR, sc = SC;
		for (int i = 0; i < N; i++) {
			if (S[i] == dirs[j]) {
				if (S[i] == 'U') sr--;
				if (S[i] == 'R') sc++;
				if (S[i] == 'D') sr++;
				if (S[i] == 'L') sc--;
			}
			if (sr<=0 || sr>H || sc<=0 || sc>W) {
				flag = true;
				break;
			}
			if (T[i] == dirt[j]) {
				if (T[i] == 'U' && sr != 1) sr--;
				if (T[i] == 'R' && sc != W) sc++;
				if (T[i] == 'D' && sr != H) sr++;
				if (T[i] == 'L' && sc != 1) sc--;
			}
		}
	}

	if (!flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
