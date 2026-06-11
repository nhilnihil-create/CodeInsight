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
	map<char,int> mp;
	string s;
	cin >> s;
	for(int i = 0;i < n;i++){
		mp[s[i]]++;
	}

	ll ans = 1;
	for(auto p:mp){
		ans *= p.second + 1; 
		ans %= MOD;
	}

	cout << (ans-1+MOD) % MOD << endl;
}
