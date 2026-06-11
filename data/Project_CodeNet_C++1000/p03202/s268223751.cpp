#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define N 200005
using namespace std;
int n,top;
int s[N],st1[N],st2[N];
bool check(int a){
	top=0;
	for(int i=1;i<=n;i++){
		if(s[i]<=s[i-1]){
			if(a==1) return 0;
			while(top>0&&st1[top]>s[i]) top--;
			if(st1[top]==s[i]) st2[top]++;
			else top++,st1[top]=s[i],st2[top]=1;
			while(st2[top]>=a&&top!=0){
				if(st1[top]-st1[top-1]==1) st2[top-1]++,top--;
				else{st1[top]--;st2[top]=1;break;}
			}
			if(top==0&&st2[top]!=0) return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	if(check(l)) printf("%d\n",l);
	else printf("%d\n",r);
	return 0;
}