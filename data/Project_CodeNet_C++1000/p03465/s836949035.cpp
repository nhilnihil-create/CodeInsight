#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int a[maxn],q[maxn*maxn],t;
bitset<maxn*maxn>f;
int main(){
	int i,j,k,m,n;
	read(n);
	int sum=0;
	f[0]=1;
	for(register int i=1;i<=n;i++){
		read(a[i]);
		sum+=a[i];
		f|=(f<<a[i]);
	}
	//sort(a+1,a+n+1); 
	int tmp=0,lim=1;
	for(register int i=1;i<=sum;i++)
		if(f[i])q[++t]=i;
	cout<<q[(t+1)/2]<<endl;
	//cout<<tmp<<endl;
	return 0;
}