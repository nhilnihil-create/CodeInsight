#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<iomanip>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const int INF = 1e9 + 7;
int main() {
	int N, H, W;
	cin >> N >> H >> W;
	int A[1010], B[1010];
	for (int i = 0; i < N; ++i)cin >> A[i] >> B[i];
	int count = 0;
	for (int i = 0; i < N; ++i) {
		if (H <= A[i] && W <= B[i])count++;
	}
	cout << count << endl;
	return 0;
}