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

#define MAXN (1 << 20)

vector<ll> over;
vector<ll> under;
ll a[MAXN], b[MAXN];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	ll sunder = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			over.push_back(a[i] - b[i]);
		} else if (a[i] < b[i]) {
			under.push_back(b[i] - a[i]);
			sunder += b[i] - a[i];
		}
	}
	sort(over.begin(), over.end());
	reverse(over.begin(), over.end());
	if (sunder == 0) {
		cout << 0 << endl;
		return 0;
	}
	ll sover = 0;
	for (int i = 0; i < over.size(); i++) {
		sover += over[i];
		if (sover >= sunder) {
			cout << i + 1 + under.size() << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}
