#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N=200010;
int L[N],R[N];
inline int gi() {
    int x=0,o=1;
    char ch=getchar();
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int main() {
    int n,m=1e5;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) ++L[gi()+m],++R[gi()+m];
    for(int i=1;i<=m+m;i++) R[i]+=R[i-1];
    for(int i=m+m;~i;i--) L[i]+=L[i+1];
    for(int i=1;i<=m;i++) ans+=min(R[i-1],L[i]+1);
    for(int i=m+1;i<=m+m;i++) ans+=min(R[i-1]+1,L[i]);
    cout<<ans*2;
    return 0;
}