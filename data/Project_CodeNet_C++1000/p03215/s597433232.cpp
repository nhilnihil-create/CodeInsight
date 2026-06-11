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
const int MOD = 1000000007;
int main(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0;i < n;i++)cin >> a[i];

	queue<ll> q;
	for(int i = 0;i < n;i++){
		ll sum = 0;
		for(int j = i;j < n;j++){
			sum += a[j];
			q.push(sum);
		}
	}

	ll comp = 1LL << 45;
	ll ans = 0;
	while(comp != 0){
		vector<ll> hold;
		int cnt = 0;
		while(q.size()){
			ll now = q.front();
			q.pop();
			hold.push_back(now);
			if(comp & now)cnt++;
		}
		if(cnt < k){
			for(int i = 0;i < hold.size();i++){
				q.push(hold[i]);
			}
		}
		else{
			ans += comp;
			for(int i = 0;i < hold.size();i++){
				if(comp & hold[i])q.push(hold[i]);
			}
		}
		comp /= 2;
	}

	cout << ans << endl;
}
