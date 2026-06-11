#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200010;
int n;
int a[N],v[N],g[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=='-'?o=-1:0,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return o*x;
}
inline bool check(int k) {
    int tp=0;
    for(int i=2;i<=n;i++) {
	if(a[i]<=a[i-1]) {
	    while(tp&&v[tp]>a[i]) --tp;
	    int t=a[i];
	    while(t) {
		if(v[tp]<t) {
		    if(k==1) return 0;
		    v[++tp]=t,g[tp]=2;
		    break;
		}
		if(g[tp]<k) {++g[tp];break;}
		--tp,--t;
	    }
	    if(!t) return 0;
	}
    }
    return 1;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=gi();
    int l=1,r=n;
    while(l<=r) {
	int mid=(l+r)>>1;
	if(check(mid)) r=mid-1;
	else l=mid+1;
    }
    cout<<l;
    return 0;
}