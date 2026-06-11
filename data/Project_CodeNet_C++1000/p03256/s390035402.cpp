#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
/*inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}*/
#define gc getchar
#define pc putchar
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
#define rank __RANK
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
int front,rear,n,m;
int q[maxn];
bool vis[maxn];
char s[maxn];
vector<int> edge[maxn];
int cnt[maxn][2];
int main(){
	n = rd(),m = rd();
	scanf("%s",s+1);
	Rep(i,1,n) s[i] -= 'A';
	Rep(i,1,m){
		int a = rd(),b = rd();
		edge[a] . push_back(b);
		edge[b] . push_back(a);
		cnt[a][s[b]]++;
		cnt[b][s[a]]++; 
	}
	front = rear = 0;
	Rep(i,1,n) if(cnt[i][0]==0 || cnt[i][1]==0){
		q[rear++] = i;
		vis[i] = true;
	}
	while(front < rear){
		int u = q[front++];
	//	printf("%d\n",u);
		for(auto v : edge[u]){
			cnt[v][s[u]]--;
			if((cnt[v][0]==0 || cnt[v][1]==0) && !vis[v]){
				q[rear++] = v;
				vis[v] = true;
			}
		}
	}
	if(rear==n){
		puts("No");
	} else{
		puts("Yes");
	}
	return 0;
}