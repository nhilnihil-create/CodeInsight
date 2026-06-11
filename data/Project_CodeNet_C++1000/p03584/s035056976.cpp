#include <bits/stdc++.h>
#define rep(n) for (int i = 0; i < n; ++i)
#define REP(n,i) for (int i = 0; i < n; ++i)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define mkt make_tuple
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int N, K, A[100000], B[100000], C;
ll MAX = 0, cnt;

int main(){
	cin >> N >> K;
	for (int i = 0; i != N; ++i) {
		cin >> A[i] >> B[i];
		if (K == (A[i] | K))
			MAX += B[i];
	}
	int k = K;
	for (int i = 1; i != 31; ++i) {
		if (k % 2) {
			K = K - K % (1 << (i - 1)) - 1;
			cnt = 0;
			for (int j = 0; j != N; ++j) {
				if (K == (A[j] | K))
					cnt += B[j];
			}
			MAX = max(MAX, cnt);
		}
		k /= 2;
	}
	cout << MAX << endl;
	return 0;
}
