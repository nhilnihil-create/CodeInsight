#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)

int main(){
    int mod=1000000007;
    int n,ans=0;
    sc1(n);
    int v[n],c[n];
    rep(i,n) sc1(v[i]);
    rep(i,n) sc1(c[i]);
    rep(i,n) if (v[i]>c[i]) ans+=v[i]-c[i];
    printf("%d\n",ans);
    return 0;
}
