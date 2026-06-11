#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define mp make_pair
int n;
const int maxn=2e5+100;
int dist[maxn];
priority_queue < pair < int,int > > q;
bool used[maxn];
void solve(){
	cin >> n;
	memset(dist,10,sizeof(dist));
	q.push(mp(0,0));
	dist[0]=0;
	while (!q.empty()){
		int u=-q.top().fi;
		int v=q.top().se;
//		cout << u << ' '<< v << endl;
		q.pop();
		if (dist[v]!=u) continue;
		used[v]=true;
		int tmp[2];tmp[1]=(v+1-1)%n+1;
		tmp[0]=(v*10-1)%n+1;
		for (int i=0;i<=1;i++){
			if (!used[tmp[i]] && dist[tmp[i]]>u+i){
				dist[tmp[i]]=u+i;
				q.push(mp(-dist[tmp[i]],tmp[i]));
			}
		}
	}
	cout << dist[n] << endl;
}
signed main(){
	solve();
	return 0;
}