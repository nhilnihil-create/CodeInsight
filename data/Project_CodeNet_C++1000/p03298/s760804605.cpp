%:pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 111;

#define int long long

char s[N];

int n;

map <pair <vector <int>, vector <int> > , int> Map[2];

main(void) {
	cin >> n;
	scanf("%s", s);
	n = strlen(s);
	n /= 2;
	int ans = 0;
	vector <int> A, B, C, D;
	int tot = 0;
	for(int i = 0; i < (1 << n); ++ i) {
		A.clear(); B.clear(); C.clear(); D.clear();
		for(register char j = 0; j < n; ++ j) {
			++ tot;
			if((i >> j) & 1) {
				A.push_back(s[j]);
				C.push_back(s[j + n]);
			}
			else {
				B.push_back(s[j]);
				D.push_back(s[j + n]);
			}
		}
		reverse(C.begin(), C.end());
		reverse(D.begin(), D.end());
		++ Map[0][make_pair(A, B)];
		ans += Map[1][make_pair(A, B)];
		++ Map[1][make_pair(C, D)];
		ans += Map[0][make_pair(C, D)];
	}
	cout << ans << endl;
}