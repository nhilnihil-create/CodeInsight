#include<bits/stdc++.h>
#define R register int
#define ll long long 
using namespace std;
const int mod=1000000007;
const int N=100001;
int n,w[N],res[N],vis[N];
int le,ri,z,y;ll ans;
vector<int>G[N];
int gi(){
    R x=0,k=1;char c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')k=-1,c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();	
    return x*k;
}
void work(R k){
	puts("Yes");
	printf("%d\n",k);
	R tot=0;
	for(R i=1;i<=k;++i)
		for(R j=i+1;j<=k;++j)
			tot++,G[i].push_back(tot),G[j].push_back(tot);
	for(R i=1;i<=k;++i){
		printf("%d ",k-1);
		for(R j=0;j<k-1;++j)
			printf("%d ",G[i][j]);
		puts("");
	}
	exit(0);
}
int main(){
	cin>>n;
	if(n==1){
		puts("Yes");
		puts("2");
		cout<<1<<' '<<1<<endl;
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	for(R k=1;k<=n;++k)
		if(k*(k-1)/2==n)
			work(k);
	puts("No");
    return 0;
}
