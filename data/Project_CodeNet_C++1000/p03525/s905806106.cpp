#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define enld endl

int main() {
	lint N;
	cin >> N;
	vector<lint>A(N);
	rep(i, N) {
		cin >> A[i];
	}
	sort(A);
	rep(i, N - 2) {
		if (A[i] == A[i + 1] && A[i + 1] == A[i + 2]) {
			cout << 0 << endl;
			return 0;
		}
	}
	vector<lint>X;
	vector<lint>Y;
	rep(i, N - 1) {
		if (A[i] == A[i + 1]) {
			X.push_back(A[i]);
			X.push_back(24 - A[i]);
			A[i] = -1;
			A[i + 1] = -1;
		}
	}
	rep(i, N) {
		if (A[i] != -1) {
			Y.push_back(A[i]);
		}
	}
	lint x = X.size();//kotei
	lint y = Y.size();//ugokasu

	

	lint cnt = 10000;
	lint ans = 0;

	
	for (int S = 0; S < 1 << y; S++) {
		cnt = 10000;
		//作成
		vector<int>V;
		rep(i, y) {
			V.push_back(S >> i & 1);
		}
		//操作
		vector<lint>CY = Y;
		rep(i, y) {
			if (V[i] == 0) {
				CY[i] = CY[i];
			}
			else {
				CY[i] = 24 - CY[i];
			}
		}
		CY.insert(CY.end(), X.begin(), X.end());
		CY.push_back(0);

		

		rep(i, CY.size()) {
			rep(j, CY.size()) {
				if (i != j) {
					cnt = min(cnt, min(24-abs(CY[i] - CY[j]),abs(CY[i]-CY[j])));
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << enld;
}