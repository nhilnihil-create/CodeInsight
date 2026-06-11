#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef pair<int, int> P;

#define pi 3.141592653589793)
#define mod 1000000007

int Q;
long long A, B;
long long ans;





void solve2() {
	long long AB = A * B;
	long long AB_sqr = sqrt(AB);
	if ((A * B) == AB_sqr*AB_sqr) AB_sqr--;
	long long tmp;

	if (A == B) tmp = 0;
	else if (AB_sqr * (AB_sqr + 1) >= AB) tmp = 2;
	else tmp = 1;

	ans = AB_sqr * 2 - tmp;
}

void solve() {
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B;
		solve2();
		cout << ans << endl;
	}
}

int main() {
	solve();
	return 0;
}