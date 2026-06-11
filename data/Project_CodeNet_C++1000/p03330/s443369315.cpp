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
typedef tuple<int,int,int> T3;

int main(){
	int n,c;
	cin >> n >> c;
	vector<vector<ll>> cost(3,vector<ll>(c+1,0));

	map<P,ll> mp;
	for(int i = 1;i <= c;i++){
		for(int j = 1;j <= c;j++){
			ll d;
			cin >> d;
			mp[P(i,j)] = d;
		}
	}

	vector<vector<int>> grid(n,vector<int>(n));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin >> grid[i][j];
		}
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			for(int k = 1;k <= c;k++){
				cost[(i+j+2)%3][k] += mp[P(grid[i][j],k)];
			}
		}
	}

	ll ans = 1e10;
	for(int i = 1;i <= c;i++){
		for(int j = 1;j <= c;j++){
			for(int k = 1;k <= c;k++){
				if(i != j && j != k && i != k){
					ans = min(ans,cost[0][i] + cost[1][j] + cost[2][k]);
				}
			}
		}
	}

	cout << ans << endl;
}
