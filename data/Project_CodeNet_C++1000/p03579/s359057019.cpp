#include <iostream>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;
const ll MAx = 1e5+5;

ll n, m, num, temp, x, y;
ll head[MAx], col[MAx], cnt[3];
struct node{
	ll ne, to;
}e[MAx<<1];
queue <ll> q;

void add(ll fr, ll to){
	e[++num].ne = head[fr]; e[num].to = to;
	head[fr] = num;
}

int bfs(){
	for(ll i = 1;i <= n;i++){
		if(!col[i]){
			col[i] = 1; temp++; q.push(i);
			cnt[col[i]]++;
			while(!q.empty()){
				ll u = q.front(); q.pop();
				for(ll j = head[u];j;j = e[j].ne){
					ll v = e[j].to;
					if(!col[v])
						col[v] = 3-col[u] , temp++,
						q.push(v), cnt[col[v]]++;
					else if(col[v] == col[u]) return 0;
				}
			}
		}
		if(temp == n) break;
	}
	return 1;
}

int main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= m;i++){
		scanf("%lld%lld", &x, &y);
		add(x, y); add(y, x);
	}
	if(bfs()) printf("%lld", cnt[1]*cnt[2]-m);
	else printf("%lld", n*(n-1)/2-m);
	return 0;
}