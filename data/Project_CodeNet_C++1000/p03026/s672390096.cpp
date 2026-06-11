#include <bits/stdc++.h>
using namespace std;
#define ALL(A) (A).begin(),(A).end()

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> to[N],cost(N),cnt(N),T(N);
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		cnt[a]++;
		cnt[b]++;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	for(int i=0;i<N;i++)cin >> cost[i];
	int start = 0;
	for(int i=0;i<N;i++){
		if(cnt[start]<cnt[i])start = i;
	}
	sort(ALL(cost),greater<int>());
	queue<int> q;
	q.push(start);
	int num = 0;
	int ans = 0;
	T[start]=cost[num];
	num++;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0;i<to[now].size();i++){
			int next = to[now][i];
			if(T[next]==0){
				T[next] = cost[num];
				ans += cost[num];
				num++;
				q.push(next);
			}
		}
	}
	cout << ans << endl;
	for(auto x:T)cout << x << " ";
}