#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define REP(i,a,n) for(int i = (a); i < (n); i++)
#define ALL(v) v.begin(), v.end()

int main() {
	string S;
	cin >> S;
	int N = S.size();
	int cnt[3] = {};
	rep(i, N) {
		cnt[S[i] - 'a']++;
	}
	rep(i, 3) {
		if (cnt[i]<N / 3 || cnt[i]>(N + 2) / 3) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}