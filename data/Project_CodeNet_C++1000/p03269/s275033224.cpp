#include<bits/stdc++.h>
using namespace std;
struct E{int u,v,c;};
int l,p=1,mx,n,s1;
vector<E> ans;
int main(){
	scanf("%d",&l);l--;
	int i;
	for(i=1;mx+p<=l;++i){
		ans.push_back({i,i+1,p});
		ans.push_back({i,i+1,0});
		mx+=p,p*=2;
	}
	n=i--,p/=2,s1=mx-p;
	while(mx<l){
		if(mx+s1+1<=l)ans.push_back({i,n,mx+1}),mx+=s1+1;
		p/=2,s1-=p,i--;
	}
	printf("%d %d\n",n,ans.size());
	for(int i=0;i<ans.size();++i)printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].c);
} 