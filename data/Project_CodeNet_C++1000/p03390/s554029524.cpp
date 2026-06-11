#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL;

using namespace std;

LL A, B;

LL mysqrt(LL x) {
	LL y = sqrt(x);
	if (y * y > x)
		y--;
	if ((y + 1LL) * (y + 1LL) <= x)
		return y + 1;
	return y;
}

int main() {
	int tests;
	cin >> tests;
	FOR (test, tests) {
		cin >> A >> B;
		if (A * B <= 1000) {
			LL ret = 0LL;
			bool usedi[A * B + 1];
			bool usedj[A * B + 1];
			SET(usedi, 0);
			SET(usedj, 0);
			ffor (i, 1, A * B + 1)
				for (int j = A * B; j > 0; j--) {
					if (usedi[i] || usedj[j])
						continue;
					if (i == A || j == B)
						continue;
					if (i * j < A * B) {
						usedi[i] = true;
						usedj[j] = true;
						ret++;
					}
				}
			cout << ret << endl;
			continue;
		}
		LL ret = 0LL;
		LL mm = A * B - 1;
		LL s = mysqrt(mm);
		ret += 2 * s;
		if (s * (s + 1) > mm)
			ret--;
		if (s >= min(A, B))
			ret--;
		cout << ret << endl;
		//cout << "ret = " << ret << "; s = " << s << "; mm  = " << mm << endl;
	}
  return 0;
}