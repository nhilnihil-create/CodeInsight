#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int n, k;
	cin >> n >> k;
	int A[n];
	rep(i, n) cin >> A[i];

	map<int, int> mp;
	rep(i, n) mp[A[i]]++;

	int cnt = 0;
	int N[n];
	for (auto p : mp) {
		N[cnt]= p.second;
		cnt++;
	}
	sort(N, N+cnt);

	if (cnt+1<=k) {
		cout << 0 << endl;
		return 0;
	}
	else {
		cout << accumulate(N, N+cnt-k, 0) << endl;
	}
}