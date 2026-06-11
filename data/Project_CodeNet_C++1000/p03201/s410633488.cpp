#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

int N;
ll A[100000 * 2 + 10];
bool used[100000 * 2 + 10];
map<ll, int> numcnt;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i], numcnt[A[i]]++;
	sort(A, A + N);
	int ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (used[i])continue;
		for (int j = 33; j >= 0; j--) {
			ll mokuhyo = 1LL << j;
			if (binary_search(A, A + N, mokuhyo - A[i])) {
				if (mokuhyo != A[i] * 2) {
					auto ptr = upper_bound(A, A + N, mokuhyo - A[i]);
					ptr--;
					auto cpyAminus = A;
					cpyAminus--;
					while (ptr != cpyAminus && used[ptr - A])ptr--;
					if (ptr == cpyAminus || mokuhyo - A[i] != *ptr) continue;
					used[i] = true;
					used[ptr - A] = true;
					ans++;
					numcnt[A[i]]--;
					numcnt[A[ptr - A]]--;
					goto nxtnumber;
				}
				else {
					//複数個あるかつ同じもの２つで2^iになるのは、最後にまとめる。
				}
			}
		}
		used[i] = true;
	nxtnumber:;
	}
	for (auto it = numcnt.begin(); it != numcnt.end(); it++) {
		bool f = false;
		for (int i = 0; i < 35; i++) {
			if ((1LL << i) == (*it).first)f = true;
		}
		if (!f)continue;
		ans += (*it).second / 2;
	}
	cout << ans << endl;
	return 0;
}