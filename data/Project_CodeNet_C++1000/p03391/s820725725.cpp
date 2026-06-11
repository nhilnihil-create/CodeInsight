#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, A, B, MIN;
ll res;

int main(){
	cin >> N;
	MIN = intmax;
	while (N--) {
		cin >> A >> B;
		if (A > B)MIN = min(MIN, B);
		res += A;
	}
	if (MIN == intmax) {
		cout << 0 << endl;
	}
	else {
		cout << res - MIN << endl;
	}
	return 0;
}