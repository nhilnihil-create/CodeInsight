#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (ll)1000000007
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n;
set<int> st;
signed main() {
	cin >> n;
	if (n == 3) {
		cout << 2 << " " << 3 << " " << 25 << endl;
		return 0;
	}
	if (n == 4) {
		cout << 2 << " " << 3 << " " << 25 << " " << 30 << endl;
		return 0;
	}
	st.insert(2);
	st.insert(3);
	st.insert(25);
	st.insert(30);
	int cnt = n - 4;
	for (int i = 30;; i += 30) {
		if (st.find(i) == st.end() && i <= 30000) {
			st.insert(i);
			cnt--;
			if (!cnt)break;
		}
		for (int j = i / 2 - 14; j < i / 2; j++) {
			if (st.find(j) != st.end() || st.find(i - j) != st.end())continue;
			if (cnt >= 2 && (j % 2 == 0 || j % 3 == 0 || j % 5 == 0)) {
				st.insert(j); st.insert(i - j);
				cnt -= 2;
				if (cnt == 1) {
					st.erase(--st.end());
					cnt++;
				}
				if (!cnt)goto kaage;
			}
		}
	}
kaage:;
	for (auto ite = st.begin(); ite != st.end(); ite++) {
		if (++ite == st.end()) {
			cout << *(--ite) << endl;
		}
		else cout << *(--ite) << " ";
	}
	return 0;
}