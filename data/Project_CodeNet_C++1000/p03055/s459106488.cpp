#include<bits/stdc++.h>
using namespace std;
const int maxn = 200001;
int len, fid, dis;
vector < int > edge[maxn];
void dfs(int now, int last, int d = 1){
	if(d > dis){
		dis = d;
		fid = now;
	}
	for(auto &i : edge[now]){
		if(last != i){
			dfs(i, now, d + 1);
		}
	}
}
bool win[maxn];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> len;
	win[1] = true;
	win[2] = false;
	for(int i = 3;i < maxn;++i)
		(win[i] = !win[i - 1] || !win[i - 2]);
	for(int i = 1;i < len;++i){
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	fid = 1;
	dfs(fid, fid);
	dis = 0;
	dfs(fid, fid);
	if(win[dis]){
		cout << "First\n";
	}
	else{
		cout << "Second\n";
	}
}
