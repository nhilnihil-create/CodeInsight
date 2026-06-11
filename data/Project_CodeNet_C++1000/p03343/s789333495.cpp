#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,len,que,a[2005],tmp[2005],ans=2147483647,ord[2005],top,last[2005],some;
inline int length(int left,int right){
	return right-left+1; 
}
inline void add(int lft,int rht){
	some=0;
	if(lft>rht||length(lft,rht)<len){
		return ;
	}
	for(register int i=lft;i<=rht;i++){
		some++;
		tmp[some]=a[i];
	}
	sort(tmp+1,tmp+some+1);
	for(register int i=rht-lft-len+2;i>=1;i--){
		top++;
		last[top]=tmp[i];
	}
}
inline int deal(int x){
	int p=1;
	top=0;
	for(register int i=1;i<=n;i++){
		if(x>a[i]){
			add(p,i-1);
			p=i+1;
		}
	}
	if(top<que){
		return 2147483647;
	}
	sort(last+1,last+top+1);
	return last[que]-x; 
}
int main(){
	scanf("%d%d%d",&n,&len,&que);
	for(register int i=1;i<=n;i++){	
		scanf("%d",&a[i]);
		ord[i]=a[i];
	}
	sort(ord+1,ord+n+1);
	n++;a[n]=-2147483647;
	for(register int i=1;i<n;i++){
		ans=min(ans,deal(ord[i]));
	}
	printf("%d\n",ans);
	return 0;
}