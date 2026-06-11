#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=2e5+5;
int n,len[MN],stk[MN],val[MN],top;
inline void insert(int pos,int x){
	while(stk[top]>pos)top--;
	if(stk[top]==pos)val[top]++;
	else stk[++top]=pos,val[top]=1;
	if(top&&val[top]==x)top--,insert(pos-1,x);
}
bool check(int x){
	stk[top=0]=val[0]=0;
	for(reg int i=2;i<=n;i++)
		if(len[i-1]>=len[i])insert(len[i],x);
	return !val[0];
}
int main(){
	scanf("%d",&n);
	for(reg int i=1;i<=n;i++)scanf("%d",len+i);
	reg int flg=1;
	for(reg int i=2;flg&&i<=n;i++)
		if(len[i]<=len[i-1])flg=0;
	if(flg)return 0*puts("1");
	reg int l=2,r=n,ans=n,mid;
	while(l<=r){
		mid=(l+r>>1);
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}