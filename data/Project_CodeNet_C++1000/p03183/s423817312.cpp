#include <bits/stdc++.h>
#define int long long
using namespace std;

struct block {int s, w, v;};
vector<block> blocks;

int cur[30005];
int pre[30005];

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	for(int i = 0;i < n;i++){
		int s, w, v; cin >> w >> s >> v;
		blocks.push_back({s,w,v});
	}
	
	sort(blocks.begin(),blocks.end(), [&](block a, block b){ return a.s + a.w > b.s + b.w; });
	
	for(block B : blocks){
		swap(pre, cur);
		for(int i = 0;i <= 30000;i++) cur[i] = pre[i];
		
		for(int i = B.w;i <= 30000;i++){
			int remS = min(B.s, i - B.w);
			cur[remS] = max(cur[remS], pre[i] + B.v);
		}
		cur[B.s] = max(cur[B.s], B.v);
	}
	
	cout << *max_element(cur,cur+30005);
}
