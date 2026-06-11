#include<bits/stdc++.h>
const int N=2e3+10;
using namespace std;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int t[4000000+10];
int sum;
int cnt;
bitset<N*N>f;
int main(){
	int n,a;
	cin>>n;
	f[0]=1;
	for(register int i=1;i<=n;i++){
		read(a);
		f|=f<<a;
		sum+=a;
	}
	for(register int i=1;i<=sum;i++){
		if(f[i])t[++cnt]=i;
	}
	printf("%d",t[(cnt+1)/2]);
	return 0;
}