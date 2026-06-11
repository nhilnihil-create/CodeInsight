#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
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
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	map<int,int> mp;
	for(int i = 0;i < n;i++){
		int a;
		cin >> a;
		mp[a]++;
	}

	int ans = 0;

	for(auto p:mp){
		if(p.second > p.first){
			ans += (p.second - p.first);
		}
		else if(p.second < p.first){
			ans += p.second;
		}
	}

	cout << ans << endl;
}
