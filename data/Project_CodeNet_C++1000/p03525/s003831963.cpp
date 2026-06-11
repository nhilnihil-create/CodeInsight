////////////////////////////////////////////
///                                      ///
///         Template ver. 1 rapel        ///
/// Fear is Temporary, Regret is Forever ///
///          Must Try and Get AC         ///
///                                      ///
////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>

#include <math.h>
#include <complex>

#include <assert.h>
#include <time.h>
//#include <chrono>
//#include <random>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define endl '\n'
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

void desperate_optimization(int precision){
  	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
  	cout.setf(ios::fixed);
  	cout.setf(ios::showpoint);
  	cout.precision(precision);
}

int arr[55];
int vis[1<<24];

int n;

int calc(int x) {
	vector<int> dt;
	dt.PB(0);
	int c = 0;
	while(x) {
		if(x & 1) dt.PB(c);
		c++;
		x /= 2;
	}
	int mx = 24;
	int nw = dt.size();
	if(nw != n + 1) return 0;
	for(int i = 0;i < nw - 1;i++) {
		mx = min(mx, dt[i + 1] - dt[i]);
	}
	mx = min(mx, (dt[0] + 24 - dt[nw - 1]) % 24);
	return mx;
}

queue<int> q[2];

void hora(int tc) {
	cin>>n;
	for(int i = 0;i < n;i++) cin>>arr[i];
	memset(vis, -1, sizeof vis);
	q[0].push(0);
	int i = 0;
	int bm = 0;
	while(i != n) {
		int target = arr[i];
		int revtarget = (24 - arr[i]) % 24;
		while(!q[bm].empty()) {
			int val = q[bm].front();
			q[bm].pop();
			int nx = ((1<<target) | val);
			if(vis[nx] != i) q[1 - bm].push(nx);
			vis[nx] = i;
			int revnx = ((1<<revtarget) | val);
			if(vis[revnx] != i) {
				q[1 - bm].push(revnx);
			}
			vis[revnx] = i;
		}
		i++;
		bm ^= 1;
	}
	int dt = 0;
	while(!q[bm].empty()) {
		int val = q[bm].front();
		q[bm].pop();
		dt = max(dt, calc(val));
	}
	cout<<dt<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}


