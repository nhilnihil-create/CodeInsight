#include<cstdio>
#include<iostream>
using namespace std;
int n,a[100005],lft=2147483647,rht=-2147483647,middle,cnt[100005],tree[100005];
inline int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
inline int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
inline int lowbit(int x){
	return x&(-x);
}
inline void insert(int i,int x){
	while(i<=n){
		tree[i]+=x;
		i+=lowbit(i); 
	}
}
inline int getsum(int i){
	int ans=0;
	while(i>0){
		ans+=tree[i];
		i-=lowbit(i);
	}
	return ans;
}
inline bool check(int x){
	long long ans=0;
	int mn=n;
	for(register int i=1;i<=n;i++){
		cnt[i]=1;
		if(a[i]>=x){
			cnt[i]=-1;
		}
	}
	for(register int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
		if(cnt[i]>0){
			ans++;
		}
		mn=min(mn,cnt[i]); 
	}
	for(register int i=1;i<=n;i++){
		tree[i]=0;
		cnt[i]+=1-mn;
	}
	for(register int i=1;i<=n;i++){
		ans+=getsum(cnt[i]-1);
		insert(cnt[i],1); 
	}
	if(ans<=1ll*n*(n+1)/4){
		return true;
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lft=min(lft,a[i]);
		rht=max(rht,a[i]);
	}
	while(lft+1<rht){
		middle=(lft+rht)/2;
		switch(check(middle)){
			case true:lft=middle;break;
			case false:rht=middle-1;break;
		}
	}
	if(check(rht)==true){
		printf("%d\n",rht);
	}
	else{
		printf("%d\n",lft);
	}
	return 0;
} 