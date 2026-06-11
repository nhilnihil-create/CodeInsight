#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int maxn = 1007;

char c[4] = {'L','R','D','U'};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n;
int x[maxn];
int y[maxn];
vector<int>ans;
signed main(){
	scanf("%lld",&n);
	bool tp = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%lld%lld",&x[i],&y[i]);
		if(i == 1)tp = ((x[i] ^ y[i]) & 1);
		else if(tp != ((x[i] ^ y[i]) & 1)){
			puts("-1");
			exit(0);
		}
	}
	for(int i = 0; i <= 30; ++i)ans.push_back((1LL << i));
	if(tp == 0)ans.push_back(1);
	sort(ans.begin(),ans.end());
	reverse(ans.begin(),ans.end());
	printf("%lld\n",ans.size());
	for(int i = 0; i < ans.size(); ++i)printf("%lld ",ans[i]);puts("");
	for(int i = 1; i <= n; ++i){
		int px = 0,py = 0;
		string Ans;
		for(int j = 0; j < ans.size(); ++j){
			int Min = 5e18,pos = -1;
			for(int d = 0; d < 4; ++d){
				int nx = px + dx[d] * ans[j],ny = py + dy[d] * ans[j];
				int dis = llabs(nx - x[i]) + llabs(ny - y[i]);
				if(dis < Min)Min = dis,pos = d;
			}
			printf("%c",c[pos]);
			px += dx[pos] * ans[j],py += dy[pos] * ans[j];
		}puts("");
	}
	return 0;
}
