#include "bits/stdc++.h"

using namespace std;

#define int long long
#define ll long long
typedef pair<int, int> P;
#define mod 998244353
#define INF (1LL<<60)

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define YES puts("YES\n")
#define Yes puts("Yes\n")
#define NO  puts("NO\n")
#define No  puts("No\n")
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }


int LIS(vector<int>& v) {
	int N = v.size();
	vector<int> dp(N, INF);

	for (int i = 0; i < N; i++)
		* lower_bound(dp.begin(), dp.end(), v[i]) = v[i];

	int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
	return ans;
}

int LDS(vector<int> v) {
	int N = v.size();
	rep(i, N) v[i] *= -1;
	vector<int> dp(N, INF);

	for (int i = 0; i < N; i++)
		* lower_bound(dp.begin(), dp.end(), v[i]) = v[i];

	int ans = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
	return ans;
}

signed main() {

	int N, A, B;
	cin >> N >> A >> B;

	if (A + B > N+1 || A * B < N) { cout << -1 << endl; return 0; }

	vector<int> v;

	//	B B-1 B-2 ... 2 1 
	//	B*2 B*2-1 ... B+2 B+1
	//  B*A B*A-1

	int del = A*B - N;
	int delg, delrem;
	if (B == 1) {
		delg = 0;
		delrem = 0;
	}
	else {
		delg = del / (B - 1);
		delrem = del % (B - 1);
	}
	for (int a = 0; a < A; a++) {
		if (a < delg) v.push_back(B * (a + 1));
		else if (a == delg) {
			for (int b = delrem; b < B; b++) v.push_back(B * (a + 1) - b);
		}else
			for (int b = 0; b < B; b++) v.push_back(B * (a + 1) - b);
	}


	vector<int> vals;
	for (int i = 0; i < v.size(); ++i) vals.push_back(v[i]);
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	for (int i = 0; i < v.size(); ++i) {
		cout << 1 + lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin() << " ";
	}
	cout << endl;

	return 0;
}