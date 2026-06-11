#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	int A, B;
	scanf("%d %d", &A, &B);
	int ans = 0;
	for (int i = A; i <= B; i++) {
		string s = to_string(i);
		string rev = s;
		reverse(rev.begin(), rev.end());
		if (s == rev) ans++;
	}
	printf("%d\n", ans);

	return 0;
}
