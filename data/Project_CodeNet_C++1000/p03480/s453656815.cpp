#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#define inf 2147483647
#define N 1000010
#define p(a) putchar(a)
#define For(i,a,b) for(int i=a;i<=b;++i)

using namespace std;
int n,cnt,ans;
int a[N];
char c[N];
void in(int &x){
    int y=1;char c=getchar();x=0;
    while(c<'0'||c>'9'){if(c=='-')y=-1;c=getchar();}
    while(c<='9'&&c>='0'){ x=(x<<1)+(x<<3)+c-'0';c=getchar();}
    x*=y;
}
void o(int x){
    if(x<0){p('-');x=-x;}
    if(x>9)o(x/10);
    p(x%10+'0');
}

signed main(){
    cin>>(c+1);
    n=(int)strlen(c+1);
    For(i,2,n){
    	if(c[i]!=c[i-1]) a[++cnt]=max(i-1,n-(i-1));
    }
    ans=n;
    For(i,1,cnt) ans=min(ans,a[i]);
    o(ans);
    return 0;
}