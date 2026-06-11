#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#define rep(i,j,k) for(int i = j; i <= k; i++) 
#define dow(i,j,k) for(int i = j; i >= k; i--) 

using namespace std;
const int N = 2e5 + 100;
int n, a[N];
vector<pair<int,int> > mp;

bool check(int index) {
	mp.clear();
	mp.push_back(make_pair(0,0));
	int sz = 0, p;
	for (int i = 2; i <= n; i++) {
		if (a[i] > a[i-1]) continue;
		while (mp[sz].first > a[i]) mp.pop_back(), sz--;
		//int j = mp.size() - 1;
		for (p = a[i]; p; p--) {
			if (mp[sz].first < p) mp.push_back(make_pair(p,0)), sz++;
			if (++mp[sz].second == index) mp.pop_back(), sz--;
			else break;
		}

		if (!p) return 0;
	}
	return 1;
}


int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	int flag = 1;
	//n = 2e5 ;
	rep(i,1,n) cin >> a[i];//a[i] = 100000000 - i * 10 ;//cin >> a[i];
	rep(i,2,n) flag &= (a[i] > a[i - 1]);
	if (flag) {
		cout << 1 << endl;
		return 0;
	}
	int l = 2, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}
	