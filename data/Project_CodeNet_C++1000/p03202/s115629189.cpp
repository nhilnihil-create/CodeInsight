#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

//解説の「比較的容易に」にハラスメントを感じる

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N;
	cin >> N;
	int A[200000];
	int ichi = 1;
	int maeichi = 0;
	rep(i, N) {
		cin >> A[i];
		if (maeichi >= A[i]) ichi = 0;
		maeichi = A[i];
	}
	if (ichi) {
		co(1);
		return 0;
	}

	int L = 2;
	int R = N;
	while (L < R) {
		int H = (L + R) / 2;
		map<int, int> MP;
		int mae = 0;
		rep(i, N) {
			int k = A[i];
			if (mae >= k) {
				auto itr = MP.upper_bound(k);
				MP.erase(itr, MP.end());
				if (MP[k] == 0) MP[k] += 2;
				else MP[k] += 1;
				while (k >= 0 && MP[k] > H) {
					MP[k] = 1;
					if (MP[k - 1] == 0) MP[k - 1] += 2;
					else MP[k - 1] += 1;
					k--;
				}
			}
			else {
				MP[k] = 1;
			}
			mae = k;
		}
		if (MP.find(0) == MP.end()) R = H;
		else L = H + 1;
	}

	co(L);

	Would you please return 0;
}