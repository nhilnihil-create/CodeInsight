#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int inf=0x3f3f3f3f;
int H, W, n;
int x[N], y[N];
vector <int> v[N],s[N];
int p[N],q[N];
int main(){
	scanf("%d%d%d",&H,&W,&n);
	for(int i=1; i<=n; ++i)scanf("%d%d",&x[i],&y[i]);
	for(int i=1; i<=n; ++i)v[x[i]].push_back(y[i]),s[y[i]].push_back(x[i]);
	for(int i=1; i<=H; ++i)sort(v[i].begin(),v[i].end());
	for(int i=1; i<=W; ++i)sort(s[i].begin(),s[i].end());
	p[1]=1;
	for(int i=1; i<H; ++i){
		v[i+1].push_back(W+1);
		int d=lower_bound(v[i+1].begin(),v[i+1].end(),p[i]+1)-v[i+1].begin();
		p[i+1]=(v[i+1][d]==p[i]+1?p[i]:p[i]+1);
	}
	int ans=inf;
	memset(q,0x3f,sizeof(q));
	for(int i=1; i<=H; ++i)q[p[i]]=min(q[p[i]],i);
	for(int i=1; i<=W; ++i)
		if(q[i]<inf){
			s[i].push_back(H+1);
			int d=lower_bound(s[i].begin(),s[i].end(),q[i])-s[i].begin();
			if(s[i][d]>q[i])ans=min(ans, s[i][d]-1);
			else{
				while(d<s[i].size()-1&&s[i][d+1]==s[i][d]+1)++d;
				if(d!=s[i].size()-1)ans=min(ans, s[i][d+1]-1);
			}
		}
	printf("%d", ans);
	return 0;
}