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

int N, H, W, cnt, A, B;

int main() {
	cin >> N >> H >> W;
	for (int i = 0; i < N; ++i) {
		cin >> A >> B;
		if (H <= A && W <= B)++cnt;
	}
	cout << cnt << endl;
	return 0;
}