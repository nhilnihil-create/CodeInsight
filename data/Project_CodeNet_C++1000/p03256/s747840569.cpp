#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
vector<int>g[210000];
char in[210000];


vector<int>scc_g[410000];
vector<int>scc_rev[410000];
int v[410000]; // used twice
int num[410000]; // inverse of conv
int conv[410000]; // dfs order of i-th vertex. note that it's kaerigake ordered
int scc[410000]; // the index of scc containing i-th vertex
int fi[410000]; // the first element of each scc
int ss[410000]; // size of each scc
int cur;
void dfs(int a){
	for(int i=0;i<scc_g[a].size();i++){
		if(v[scc_g[a][i]])continue;
		v[scc_g[a][i]]=1;
		dfs(scc_g[a][i]);
	}
	conv[a]=cur;
	num[cur++]=a;
}
void dfs2(int a){
	scc[a]=cur;
	ss[cur]++;
	for(int i=0;i<scc_rev[a].size();i++){
		if(v[scc_rev[a][i]])continue;
		v[scc_rev[a][i]]=1;
		dfs2(scc_rev[a][i]);
	}
}

int main(){
	int a,b;scanf("%d%d",&a,&b);
	scanf("%s",in);
	for(int i=0;i<b;i++){
		int p,q;scanf("%d%d",&p,&q);p--;q--;
		g[p].push_back(q);
		g[q].push_back(p);
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<g[i].size();j++){
			int to=g[i][j];
			if(in[i]!=in[g[i][j]]){
				scc_g[i*2].push_back(g[i][j]*2+1);
				scc_rev[g[i][j]*2+1].push_back(i*2);
			}else{
				scc_g[i*2+1].push_back(g[i][j]*2);
				scc_rev[g[i][j]*2].push_back(i*2+1);
			}
		}
	}
	int n=a*2;
	for(int i=0;i<n;i++){
		if(v[i])continue;
		v[i]=1;
		dfs(i);
	}
	cur=0;
	for(int i=0;i<n;i++)v[i]=0;
	for(int i=n-1;i>=0;i--){
		if(v[num[i]])continue;
		v[num[i]]=1;
		fi[cur]=num[i];
		dfs2(num[i]);
		cur++;
	}
	for(int i=0;i<cur;i++){
		if(ss[i]>=4){
			printf("Yes\n");return 0;
		}
	}printf("No\n");
}
