#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500100;

char s[N];
string w = "";

int main() {

	scanf("%s", s);

	int n = strlen(s);

	for (int i = 0; i < n;) {
		if (s[i] == 'A') {
			w += 'A';
			i += 1;
		} else if (i + 1 < n && s[i] == 'B' && s[i + 1] == 'C') {
			w += 'D';
			i += 2;
		} else {
			w += s[i];
			i++;
		}
	}

	long long res = 0;

	for (int i = w.size() - 1, cnt = 0; i >= 0; i--) {
		if (w[i] == 'A') {
			res += cnt;
		} else if (w[i] == 'D') {
			cnt++;
		} else {
			cnt = 0;
		}
	}

	printf("%lld\n", res);

	return 0;

}