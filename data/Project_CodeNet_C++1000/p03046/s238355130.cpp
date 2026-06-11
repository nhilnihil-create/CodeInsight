#include <bits/stdc++.h>
using namespace std;

void init () {
	srand (time(0));
	int XOR[20] = {0};
	for (int n = 1; n <= 3; ++n) {
		for (int k = 1; k < (1<<n); ++k) {
			vector <int> a(1<<(n+1));
			for (int i = 0; i < (1<<n); ++i) a[i] = i, a[i+(1<<n)] = i;
			sort (a.begin(),a.end());
			cout << "n = " << n << ", k = " << k << endl;
			int times = 0;
			do {
				random_shuffle(a.begin(),a.end());
				int cnt = 0;
				vector <int> pos[1<<n];
				XOR[0] = 0;
				for (auto &x : a) ++cnt, XOR[cnt] = XOR[cnt-1] ^ x, pos[x].push_back(cnt);
				bool flag = true;
				for (int i = 0; i < (1<<n); ++i) {
					int pos1 = pos[i][0], pos2 = pos[i][1];
//					cout << "i = " << i << ", pos1 = " << pos1 << ", pos2 = " << pos2 << endl;
					if (pos1 > pos2) swap (pos1, pos2);
					int t = XOR[pos2] ^ XOR[pos1-1];
					if (t != k) flag = false;
				}
				/*
				for (auto &x : a) cout << x << " "; cout << endl;
				for (int i = 1; i <= cnt; ++i) cout << XOR[i] << " "; cout << endl;
				cout << endl;
				*/
				if (flag) {
					cout << "YES : " << n << " " << k << endl;
					for (auto &x : a) cout << x << " "; cout << endl;
					for (int i = 0; i < (1<<n); ++i) cout << pos[i][0] << " " << pos[i][1] << endl;
					break;
				}
			} while (++times < 12345678);
//			} while (next_permutation(a.begin(),a.end()));
		}
	}
}
int main () {
	//init();
	int n, k; cin >> n >> k;
	if (k >= (1<<n) || (n == 1 && k == 1)) puts("-1");
	else if (n == 1) puts("0 0 1 1");
	else {
		vector <int> ans;
		for (int i = 0; i < (1<<n); ++i) if (i != k) ans.push_back (i);
		ans.push_back (k);
		for (int i = (1<<n)-1; i >= 0; --i) if (i != k) ans.push_back (i);
		ans.push_back (k);
		for (auto &x : ans) cout << x << " "; cout << endl;
	}
	return 0;
}