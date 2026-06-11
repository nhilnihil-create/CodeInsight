#include<bits/stdc++.h>
using namespace std;
const int maxn=200005,tt=1e9+7;
int n,c[maxn],las[maxn],f[maxn];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&c[i]);
    f[0]=1;
    for (int i=1;i<=n;i++){
        f[i]=f[i-1];
        if (las[c[i]]!=i-1&&las[c[i]]) f[i]=(f[i]+f[las[c[i]]])%tt;
        las[c[i]]=i;
        //printf("%d %d\n",i,f[i]);
    }
    printf("%d\n",f[n]);
    return 0;
}
