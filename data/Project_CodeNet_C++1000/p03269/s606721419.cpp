#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define fastin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
int a[30],p,n,sv;
int ans[110][3],q;
void add(int u,int v,int w){
	q++;
	ans[q][0]=u;
	ans[q][1]=v;
	ans[q][2]=w;
} 
int main(){
	scanf("%d",&n);
	sv=n;
	while(n){
		a[++p]=n%2;
		n/=2;
	}
	rep(i,2,18){
		add(i,i+1,0);
	}
	rep(i,2,18){
		add(i,i+1,1<<(20-i));
	}
	rep(i,0,3)	add(19,20,i);
	int base=0;
	int tmp=2*a[2]+a[1];
	rep(i,0,tmp-1)	add(1,20,i);
	base+=tmp;
	rep(i,3,p){
		if(a[i]){
			int to=22-i;
			add(1,to,base);
			base+=(1<<(i-1));
		}
	}
	printf("20 %d\n",q);
	rep(i,1,q){
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}