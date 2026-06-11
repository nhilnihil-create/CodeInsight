#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int N;
	cin >> N;
	vector<int> T(N);
	vector<int> S(N);
	for (int i = 0;i < N;i++) {
		cin >> T[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> S[i];
	}
	vector<int> mxs(1, 0);
	for (int i = 0;i < N;i++) {
		while (T[i]) {
			mxs.push_back(S[i]);
			T[i]--;
		}
	}
	mxs.push_back(0);
	int k = mxs.size();
	double al[110][20010];
	double ans = 0;
	for (int i = 0;i < 102;i++) {
		for (int j = 0;j < k;j++) {
			if (i == 0)	break;
			if (al[i - 1][j] < 1 || mxs[j] < i) {
				al[i][j] = 0;
			}
			else {
				al[i][j] = 1;
			}
		}
		for (int j = 0;j < k;j++) {
			if (i == 0) {
				al[i][j] = 1;
				continue;
			}
			if (al[i][j] == 0)
				continue;
			if (al[i][j - 1] == 0)
				al[i][j] /= 2;
			if (al[i][j + 1] == 0)
				al[i][j] /= 2;
			ans += al[i][j];
		}
	}
	printf("%lf\n",ans);
}