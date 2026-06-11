#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
#include<string.h>
#include<cstring>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> cnt(100);
	for (int i = 2; i <= n; i++) {
		int ki = i;
		for (int j = 2; j * j <= i; j++) {
			if (ki % j == 0) {
				int cntj = 0;
				while (ki % j == 0) {
					cntj++;
					ki /= j;
				}
				cnt[j] += cntj;
			}
		}
		if (ki != 1) cnt[ki]++;
	}
	int ans = 0;
	if (cnt[2] >= 74) ans++;
	for (int i = 2; i <= 98; i++) {
		for (int j = i + 1; j < 99; j++) {
			if (cnt[i] >= 2 && cnt[j] >= 24) ans++;
			if (cnt[i] >= 24 && cnt[j] >= 2) ans++;
			if (cnt[i] >= 4 && cnt[j] >= 14) ans++;
			if (cnt[i] >= 14 && cnt[j] >= 4) ans++;
		}
	}
	for (int i = 2; i <= 97; i++) {
		for (int j = i + 1; j <= 98; j++) {
			for (int k = j + 1; k <= 99; k++) {
				if (cnt[i] >= 2 && cnt[j] >= 4 && cnt[k] >= 4) ans++;
				if (cnt[i] >= 4 && cnt[j] >= 2 && cnt[k] >= 4) ans++;
				if (cnt[i] >= 4 && cnt[j] >= 4 && cnt[k] >= 2) ans++;
			}
		}
	}
	cout << ans << endl;
}