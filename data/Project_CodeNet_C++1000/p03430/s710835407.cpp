#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define gc getchar
#define pc putchar
#define fi first
#define queue QQQ
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RAnK
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
#define rd read
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int maxn = 2e5+233;
int f[305][305][305];
char s[305];
int K,n;
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	K = rd();
	mem(f,0);
	Rep(i,1,n){
		Rep(k,0,K) f[i][i][k] = 1;
	}
	Rep(len,2,n){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			Rep(k,0,K){
				if(k)f[i][j][k] = max(f[i][j][k],f[i][j][k-1]);
				f[i][j][k] = max(f[i][j][k],f[i+1][j][k]);
				f[i][j][k] = max(f[i][j][k],f[i][j-1][k]);
				if(s[i]==s[j]) f[i][j][k] = max(f[i][j][k],f[i+1][j-1][k]+2);
				if(k)f[i][j][k] = max(f[i][j][k],f[i+1][j-1][k-1]+2);
			}
		}
	}writeln(f[1][n][K]);
	return 0;
}
