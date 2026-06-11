#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=100010;
int n;
int a[N],v[N],c[N*2];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
inline bool check(int k) {
    memset(c,0,sizeof(c));
    int x=0,y=1;c[N]=1;
    long long sum=0;
    for(int i=1;i<=n;i++) {
	if(a[i]>=k) y+=c[++x+N],++c[x+N];
	else y-=c[x+N],++c[--x+N];
	sum+=y++;
    }
    return sum*2>=1LL*n*(n+1)/2;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=v[i]=gi();
    sort(v+1,v+1+n);
    for(int i=1;i<=n;i++) a[i]=lower_bound(v+1,v+1+n,a[i])-v;
    int l=1,r=n;
    while(l<=r) {
	int mid=(l+r)>>1;
	if(check(mid)) l=mid+1;
	else r=mid-1;
    }
    cout<<v[r];
    return 0;
}