#include <stdio.h>
#include <algorithm>
#include <vector>
int n,m,p[100003],y[100003];std::vector<int> a[100003];
main(){
    scanf("%d%d",&n,&m);for(int i=1;i<=m;i++) scanf("%d%d",&p[i],&y[i]),a[p[i]].push_back(y[i]);
    for(int i=1;i<=n;i++) std::sort(a[i].begin(),a[i].end());
    for(int i=1;i<=m;i++) printf("%012lld\n",p[i]*1000000ll+(std::lower_bound(a[p[i]].begin(),a[p[i]].end(),y[i])-a[p[i]].begin()+1));
    return 0;
}