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
#define OVER9000 1234567890123456789LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<uint64_t> pos_sum(2000*N/64+2, 0);
	pos_sum[0] = 1;
	cat sum = 0;
	for(int i = 0; i < N; i++) {
		int a;
		cin >> a;
		for(int j = sum/64; j >= 0; j--) {
			if(a%64 != 0) pos_sum[j+a/64+1] |= pos_sum[j] >> (64-a%64);
			pos_sum[j+a/64] |= pos_sum[j] << (a%64);
		}
		sum += a;
	}
	for(int s = sum-sum/2; s <= sum; s++) if((pos_sum[s/64]>>(s%64))&1) {
		cout << s << "\n";
		return 0;
	}
	return 0;
}

// look at my code
// my code is amazing
