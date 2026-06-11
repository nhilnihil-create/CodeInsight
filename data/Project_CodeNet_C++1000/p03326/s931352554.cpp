#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000009;

int main(){
	int n,m;
	cin >> n >> m;
	vector<ll> x(n);
	vector<ll> y(n);
	vector<ll> z(n);

	for(int i = 0;i < n;i++){
		cin >> x[i] >> y[i] >> z[i];
	}

	vector<ll> a[8];
	for(int i = 0;i < n;i++){
		a[0].push_back(x[i]+y[i]+z[i]);
	}

	for(int i = 0;i < n;i++){
		a[1].push_back(x[i]+y[i]-z[i]);
	}

	for(int i = 0;i < n;i++){
		a[2].push_back(x[i]-y[i]+z[i]);
	}

	for(int i = 0;i < n;i++){
		a[3].push_back(-x[i]+y[i]+z[i]);
	}

	for(int i = 0;i < n;i++){
		a[4].push_back(-x[i]-y[i]+z[i]);
	}

	for(int i = 0;i < n;i++){
		a[5].push_back(-x[i]+y[i]-z[i]);
	}

	for(int i = 0;i < n;i++){
		a[6].push_back(x[i]-y[i]-z[i]);
	}

	for(int i = 0;i < n;i++){
		a[7].push_back(-x[i]-y[i]-z[i]);
	}

	for(int i = 0;i < 8;i++)sort(a[i].begin(),a[i].end(),greater<ll>());

	ll sum[8] = {};
	for(int i = 0;i < m;i++){
		for(int k = 0;k < 8;k++)sum[k] += a[k][i];
	}

	ll ans = 0;
	for(int i = 0;i < 8;i++)ans = max(ans,sum[i]);
	cout << ans << endl;
}
