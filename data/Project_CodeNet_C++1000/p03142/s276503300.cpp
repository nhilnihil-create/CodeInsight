#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;


int n, m, a[101010], b[101010];
vector<int> v[101010], vv[101010];

int main(){
	cin >> n >> m;
	for(int i = 0; i < n-1 + m; i++){
		cin >> a[i] >> b[i];
		v[a[i]].push_back(b[i]);
		vv[b[i]].push_back(a[i]);
	}
	
	int t = 0;
	for(int i = 1; i <= n; i++){
		if(vv[i].size() == 0) t = i;
	}
	
	queue<P> q;
	q.push(P(0,t));
	int ans[101010] = {0}, cnt[101010] = {0};
	while(!q.empty()){
		P p = q.front();
		q.pop();
		int prev = p.first, now = p.second;
		ans[now] = prev;
		for(int i = 0; i < v[now].size(); i++){
			cnt[v[now][i]]++;
			if(vv[v[now][i]].size() > cnt[v[now][i]]){
				continue;
			}
			q.push(P(now, v[now][i]));
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
	
	return 0;
}