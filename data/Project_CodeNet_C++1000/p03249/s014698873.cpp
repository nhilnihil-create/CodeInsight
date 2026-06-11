#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define fors(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) < (y) ? (y) : (x))
#define swap(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))
#define abs(x) ((x) < 0 ? -(x) : (x)) 
const int maxn=1e6+7;
typedef long long ll;
const int inf=1<<25;
ll read(){
    ll s=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0' && c<='9') {s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0) {putchar('-');x=-x;}
    if(x>9) write(x/10);
    putchar(x%10+48);
}
int tree[101010];
ll d[101010];
int siz[101010],fa[101010];
int cmp(int x,int y){
    return d[x] < d[y];
}
map<ll,int> maps;
int main()
{
    ll n=read();
    maps.clear();
    fors(i,1,n){
        d[i]=read();
        siz[i]=1;
        maps[d[i]]=i;
        tree[i]=i;
    }
    sort(tree+1,tree+n+1,cmp);
    for(int i=n;i>1;i--){
        fa[tree[i]]=maps[ d[tree[i]]+ 2*siz[tree[i]] -n ];
        if(!fa[tree[i]]){
            printf("-1");
            return 0;
        }
        siz[fa[tree[i]]]+=siz[tree[i]];
    }
    fors(i,2,n)
        d[tree[1]]-=siz[tree[i]];
    if(d[tree[1]]){
        printf("-1");
        return 0;
    }
    fors(i,2,n)
        printf("%d %d\n",fa[tree[i]],tree[i]);
    return 0;
}