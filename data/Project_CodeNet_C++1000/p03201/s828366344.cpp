#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;

int main(){
	int n;
	cin >> n;
	map<int,int> mp;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}

	sort(a.begin(), a.end(), greater<int>());

	int ans = 0;
	for(int i = 0;i < n;i++){
		int now = 1;
		//今見ている数より大きい最小の2べき
		while(now <= a[i]){
			now *= 2;
		}

		if(mp[a[i]] == 0)continue;

		if(a[i] * 2 == now){
			if(mp[a[i]] >= 2){
				ans++;
				mp[a[i]] -= 2;
			}
		}
		else{
			if(mp[now - a[i]] > 0){
				ans++;
				mp[now-a[i]]--;
				mp[a[i]]--;
			}
		}
	}

	cout << ans << endl;
}
