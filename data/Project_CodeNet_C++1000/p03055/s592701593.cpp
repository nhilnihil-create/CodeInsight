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
#include <unordered_map>
#include <set>
#include <unordered_set>
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

const int N = 2e5;
int dist[N + 5];

vector<int> lst[N + 5];
queue<int> q;

int diameter(int n) {
	memset(dist, -1, sizeof dist);
	int pos;
	q.push(1);
	dist[1] = 0;
	while(!q.empty()) {
		pos = q.front();
		q.pop();
		for(auto x: lst[pos]) {
			if(dist[x] == 0) continue;
			dist[x] = 0;
			q.push(x);
		}
	}
	q.push(pos);
	dist[pos] = 1;
	while(!q.empty()) {
		pos = q.front();
		q.pop();
		for(auto x: lst[pos]) {
			if(dist[x] != 0) continue;
			dist[x] = dist[pos] + 1;
			q.push(x);
		}
	}
	return dist[pos] % 3;
}

void hora(int tc) {
	int n;
	cin>>n;
	for(int i = 1;i < n;i++) {
		int u, v;
		cin>>u>>v;
		lst[u].PB(v);
		lst[v].PB(u);
	}
	int l = diameter(n);
	if(l == 2) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
}

int main(){
	desperate_optimization(10);
	int ntc = 1;
	//cin>>ntc;
	for(int tc = 1;tc <= ntc;tc++) hora(tc);
	return 0;
}
