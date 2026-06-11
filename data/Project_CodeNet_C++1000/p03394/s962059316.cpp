#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100100;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
int n,q[N],sm,sum,i;
int main(){
	//freopen("1.out","w",stdout);
	n=read();
	if(n==3){puts("2 5 63");return 0;}
	for(i=2;sm<n;i++){
		if(i%2==0||i%3==0){
			q[++sm]=i;sum+=i;
		}
	}
	if(sum%2||sum%3){
		sum-=q[sm];sm--;
		sum-=q[sm];sm--;
		for(i=q[sm]+1;sm<n-1;i++)
		if((i%2==0||i%3==0)&&((sum+i)%2==0)){
			q[++sm]=i;sum+=i;
		}
		for(i=q[sm]+1;sm<n;i++)
		if((i%2==0)&&((sum+i)%3==0)){
			q[++sm]=i;sum+=i;
		}
	}
	for(i=1;i<=n;i++)printf("%d ",q[i]);
	puts("");
	return 0;
}
