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
	map<int,int> mp;

	int n;
	cin >> n;
	for(int i = 2;i <= n;i++){
		int k = i;
		for(int j = 2;j * j <= k;j++){
			while(k % j == 0){
				k /= j;
				mp[j]++;
			}
		}
		if(k != 1)mp[k]++;
	}

	vector<int> v;
	for(auto p:mp)v.push_back(p.second);


	ll ans = 0;

	int m = v.size();
	for(int i = 0;i < m-2;i++){
		for(int j = i + 1;j < m - 1;j++){
			for(int k = j + 1;k < m;k++){
				if(v[i] >= 2 && v[j] >= 4 && v[k] >= 4)ans++;
				if(v[i] >= 4 && v[j] >= 2 && v[k] >= 4)ans++;
				if(v[i] >= 4 && v[j] >= 4 && v[k] >= 2)ans++;
			}
		}
	}

	for(int i = 0;i < m;i++){
		if(v[i] >= 74)ans++;
	}

	for(int i = 0;i < m - 1;i++){
		for(int j = i + 1;j < m;j++){
			if(v[i] >= 2 && v[j] >= 24)ans++;
			if(v[i] >= 24 && v[j] >= 2)ans++;
			if(v[i] >= 4 && v[j] >= 14)ans++;
			if(v[i] >= 14 && v[j] >= 4)ans++;
		}
	}

	cout << ans << endl;
}
