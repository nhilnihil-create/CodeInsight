#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#define SF scanf
#define PF printf
#define MAXN 100010
using namespace std;
typedef long long ll;
ll bits[50],now[50];
int n,m;
ll x[MAXN],y[MAXN];
bool flag[2];
int main(){
	SF("%d",&n);
	for(int i=1;i<=n;i++){
		SF("%lld%lld",&x[i],&y[i]);
		flag[((x[i]+y[i])%2+2)%2]=1;
	}
	if(flag[0]==1&&flag[1]==1){
		PF("-1");
		return 0;
	}
	bits[0]=1;
	for(int i=1;i<40;i++)
		bits[i]=bits[i-1]*2ll;
	if(flag[1]==1){
		m=39;
		PF("39\n");
		for(int i=0;i<39;i++){
			PF("%lld ",bits[i]);
			now[i]=bits[i];
		}
		PF("\n");
	}
	else{
		m=40;
		PF("40\n1 ");
		now[0]=1;
		for(int i=0;i<39;i++){
			PF("%lld ",bits[i]);
			now[i+1]=bits[i];
		}
		PF("\n");
	}
	stack<char> s;
	for(int i=1;i<=n;i++){
		for(int j=m-1;j>=0;j--){
			ll t1=x[i]+y[i];
			ll t2=x[i]-y[i];
			if(t1>=0&&t2>=0){
				s.push('R');
				x[i]-=now[j];
			}
			else if(t1>=0&&t2<=0){
				s.push('U');
				y[i]-=now[j];
			}
			else if(t2<=0&&t1<=0){
				s.push('L');
				x[i]+=now[j];
			}
			else{
				s.push('D');
				y[i]+=now[j];
			}
		}
		while(!s.empty()){
			PF("%c",s.top());
			s.pop();
		}
		PF("\n");
	}
}
