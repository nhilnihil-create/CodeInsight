#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define INF 1e18
#define MOD 1000000007
#define N 1000005
#define BB(V) V[V.size()-2]
#define ex(V) return printf(V),0
using namespace std;
vector<pii>l_list[22];
int main(){
	int l;
	scanf("%d",&l);
	int p;
	for(p=0;(1<<p)<=l;p++);
	for(int i=0;i<p-1;i++){
		l_list[i+1].pb({i+2,0});
		l_list[i+1].pb({i+2,(1<<i)});
	}
	int cnt=1<<(p-1);
	for(int i=p-2;i>=0;i--){
		if(l&(1<<i)){
			l_list[i+1].pb({p,cnt});
			cnt+=(1<<i);
		}
	}
	cnt=0;
	for(int i=1;i<=p;i++)cnt+=l_list[i].size();
	printf("%d %d\n",p,cnt);
	for(int i=1;i<=p;i++)for(auto &p:l_list[i])printf("%d %d %d\n",i,p.F,p.S);
}