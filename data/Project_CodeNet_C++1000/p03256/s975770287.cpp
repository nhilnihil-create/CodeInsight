#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200010;
int tt;
char w[N],s[N];
int head[N],to[N*2],nxt[N*2],v[N],in[N][2];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return o*x;
}
int main() {
    int n,m,tp=0;
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i=1;i<=m;i++) {
	int x=gi(),y=gi();
	++in[y][s[x]-'A'],++in[x][s[y]-'A'];
	to[++tt]=y,nxt[tt]=head[x],head[x]=tt;
	to[++tt]=x,nxt[tt]=head[y],head[y]=tt;
    }
    for(int i=1;i<=n;i++)
	if(!in[i][0]||!in[i][1]) v[++tp]=i,w[i]=1;
    while(tp) {
	int x=v[tp--];
	for(int i=head[x];i;i=nxt[i]) {
	    int y=to[i];
	    if(!w[y]&&!--in[y][s[x]-'A']) v[++tp]=y,w[y]=1;
	}
    }
    for(int i=1;i<=n;i++)
	if(!w[i]) return puts("Yes"),0;
    puts("No");
    return 0;
}