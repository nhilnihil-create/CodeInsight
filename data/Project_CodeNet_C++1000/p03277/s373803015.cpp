#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct fin {
	vector<int> T;
	fin(int N) : T(N+10, 0) {}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int ans_mi = 0, ans_mx = OVER9000;
	while(ans_mx-ans_mi > 1) {
		int med = (1LL*ans_mi + ans_mx) / 2;
		// number of substrings with median < med
		vector<int> sum(N+1, 0);
		for(int i = 0; i < N; i++) {
			if(A[i] < med) sum[i+1] = 1;
			else sum[i+1] = -1;
			sum[i+1] += sum[i];
		}
		fin F(2*N);
		cat cnt = 0;
		for(int i = 0; i <= N; i++) {
			cnt += F.get(sum[i]+N-1);
			F.put(sum[i]+N, 1);
		}
		if(cnt > 1LL*N*(N+1)/2-cnt) ans_mx = med;
		else ans_mi = med;
	}
	cout << ans_mi << "\n";
	return 0;
}

// look at my code
// my code is amazing
