#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (1 << 10)

int a[MAXN];
int n;
int sum;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int ret = MAXN * MAXN * MAXN;
	int ind = -1;
	for (int i = 0; i < n; i++) {
		int cur = abs(n * a[i] - sum);
		if (cur < ret) {
			ret = cur;
			ind = i;
		}
	}
	cout << ind << endl;
	return 0;
}
