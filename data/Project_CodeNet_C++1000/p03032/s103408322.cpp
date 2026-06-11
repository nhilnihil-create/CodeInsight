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
	vector<int> v(n);
	for(int i = 0;i < n;i++)cin >> v[i];

	ll ans = 0;

	for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++){
			if(i + j > n || i + j > k)continue;
			ll now = 0;

			priority_queue<int,vector<int>,greater<int>> q;
			for(int l = 0;l < i;l++){
				now += v[l];
				q.push(v[l]);
			}
			for(int l = 0;l < j;l++){
				now += v[n-1-l];
				q.push(v[n-1-l]);
			}

			int cnt = k - (i + j);
			while(q.size() && q.top() < 0 && cnt > 0){
				cnt--;
				now -= q.top();
				q.pop();
			}

			ans = max(now,ans);
		}
	}

	cout << ans << endl;
}
