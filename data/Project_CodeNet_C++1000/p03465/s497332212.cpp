#include<cstdio>
#include<bitset>
#define ll long long
using namespace std;
inline ll read() {
	ll ans=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') {f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9') {ans=ans*10+ch-48;ch=getchar();}
	return ans*f;
}
bitset<4000032> b;
int n,sum;
int main() {
	n=read();
	b[0]=1;
	for (int i=1;i<=n;i++){
		int x=read();
		b|=b<<x;
		sum+=x;
	}
	for (int i=(sum+1)>>1;i<=sum;i++){
		if(b[i]){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}