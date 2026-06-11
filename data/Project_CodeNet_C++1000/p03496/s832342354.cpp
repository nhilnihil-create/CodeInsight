#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main() {
  int N;
	cin >> N;
	vector<ll> a(N);
	vector<pair<int, int>> op; // 操作

	ll absmax = 0;
	ll max_id = -1;
	rep(i, N) {
		cin >> a[i];
		if(absmax < abs(a[i])) {
			max_id = i;
			absmax = abs(a[i]);
		}
	}

	if(a[max_id]>0) {
		rep(i, N-1) {

			while(a[i]>a[i+1]) { // 高々2回で完了する
				a[i+1] += a[max_id];
				op.push_back(make_pair(max_id+1, i+2));

				if(a[max_id]<a[i+1]) {
					max_id = i;
				}
			}

		}
	} else if(a[max_id]<0){ // a[max_id] <0 
		rep(j, N-1) {
			int i = N-2-j;
			while(a[i]>a[i+1]) { // 高々2回で完了する
				a[i] += a[max_id];
				op.push_back(make_pair(max_id+1, i+1));

				if(a[max_id]>a[i]) {
					max_id = i;
				}
			}

		}
	}


	cout << op.size() << endl;
	rep(i, op.size()) {
		cout << op[i].first << ' ' << op[i].second << endl;
	}
	
	// cout << "after a[]: " << endl;
	// rep(i, N) cout << a[i] << ' ';
	// cout << endl;

  return 0;
}