#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
const int MX = 100005;
int n, m, a, b, dep[MX];
ll cnt[2];
bool f;
queue<int> qu;
vector<int> G[MX];
int main(){
	scanf("%d%d", &n, &m);
	rep(i,m){
		scanf("%d%d", &a, &b);a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	qu.push(0); cnt[0] = 1;
	fill(dep+1, dep+n, -1);
	while(!qu.empty()){
		int t = qu.front(); qu.pop();
		for(int nx: G[t]){
			if(dep[nx] == -1){
				dep[nx] = !dep[t];
				cnt[dep[nx]]++;
				qu.push(nx);
			}else if(dep[nx] == dep[t]) f = true;
		}
	}
	printf("%lld\n", (f ? (ll)n*(n-1)/2 : cnt[0]*cnt[1]) - m);
}