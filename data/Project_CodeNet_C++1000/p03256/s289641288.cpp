#include<bits/stdc++.h>
using namespace std;

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define data asd09123jdf02i3h

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e6+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int n,m,a[maxn],b[maxn],cnt,vis[maxn];
char s[maxn];
set<int > e[maxn];

int main() {
    read(n),read(m);scanf("%s",s+1);
    for(int i=1,x,y;i<=m;i++) {
        read(x),read(y);
        if(e[x].find(y)!=e[x].end()) continue;
        e[x].insert(y),e[y].insert(x);
        if(s[y]=='A') a[x]++;else b[x]++;
        if(s[x]=='A') a[y]++;else b[y]++;
    }
    queue<int > q;
    for(int i=1;i<=n;i++) if(!min(a[i],b[i])) q.push(i);
    while(!q.empty()) {
        int x=q.front();q.pop();
        if(vis[x]) continue;
        // printf("? : %d %d %d\n",x,a[x],b[x]);
        vis[x]=1;cnt++;
        for(auto v:e[x]) {
            if(v!=x) e[v].erase(x);
            if(s[x]=='A') a[v]--;
            else b[v]--;
            if(!min(a[v],b[v])) q.push(v);
        }
        e[x].clear();
    }
    puts(cnt!=n?"Yes":"No");
    return 0;
}
