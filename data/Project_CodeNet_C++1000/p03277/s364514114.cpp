#include <bits/stdc++.h>
using namespace std;
int N;
int R;
int a[500005],s[500005],Tree[500005];
int Lowbit(int x){	return x&-x;}
void Insert(int Now,int x){for (int i=Now;i<=2*N;i+=Lowbit(i)) Tree[i]+=x;}
long long query(int Now){long long ans=0;for (int i=Now;i;i-=Lowbit(i)) ans+=Tree[i];return ans;}
bool Check(int Now){
	for (int i=1;i<=2*N;i++) Tree[i]=0;
	s[0]=0;
	for (int i=1;i<=N;i++)
		if (a[i]>=Now) s[i]=s[i-1]+1;
			else s[i]=s[i-1]-1;
	long long ans=0;
	for (int i=0;i<=N;i++){
		ans+=query(s[i]+N);		
		Insert(s[i]+N,1);
	}
	return (ans>=1ll*N*(N+1)/4);
}
int main(){
	int ll=0;
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		R=max(R,a[i]);
	}
	while (ll<=R){
		int mid=(ll+R)>>1;
		if (Check(mid)) ll=mid+1;
		else R=mid-1;
	}
	cout<<R;
	return 0;
}