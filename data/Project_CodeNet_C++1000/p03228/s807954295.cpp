#include <bits/stdc++.h>
#define sp ' '
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;
const int mod998 = 998244353;

int A, B, K;

int main() {
	cin >> A >> B >> K;
	for (int i = 0; i < K; ++i) {
		if (i % 2 == 0) {
			A -= A % 2;
			B += A / 2;
			A /= 2;
		}
		else {
			B -= B % 2;
			A += B / 2;
			B /= 2;
		}
	}
	cout << A << sp << B << endl;
	return 0;
}