#include<bits/stdc++.h>
using namespace std;
#define maxn 100020
#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pr;

int d[40];
int x[maxn],y[maxn],n,tag;
int num;
char ch[40];

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d %d",&x[i],&y[i]);
	tag = (x[1] + y[1]) & 1;
	rep(i,1,n) if ( ((x[i] + y[i]) & 1) != tag ) return printf("-1\n"),0;
	if ( !tag ){
		num = 31;
		d[31] = 1;
		rep(i,1,n) x[i]--;
		ch[31] = 'R';
	}
	else num = 30;
	rep(i,0,30) d[i] = 1 << i;
	printf("%d\n",num + 1);
	rep(i,0,num) printf("%d ",d[i]);
	puts("");
	rep(i,1,n){
		repd(j,30,0){
			int lim = d[j] - 1;
			if ( (ll)abs(x[i] + d[j]) + abs(y[i]) <= lim ){
				ch[j] = 'L';
				x[i] += d[j];
			}
			else if ( (ll)abs(x[i] - d[j]) + abs(y[i]) <= lim ){
				ch[j] = 'R';
				x[i] -= d[j];
			}
			else if ( (ll)abs(y[i] + d[j]) + abs(x[i]) <= lim ){
				ch[j] = 'D';
				y[i] += d[j];
			}
			else if ( (ll)abs(y[i] - d[j]) + abs(x[i]) <= lim ){
				ch[j] = 'U';
				y[i] -= d[j];
			}
		}
	//	cout<<x[i]<<" "<<y[i]<<endl;
		rep(j,0,num) putchar(ch[j]);
		puts("");
	}
}
