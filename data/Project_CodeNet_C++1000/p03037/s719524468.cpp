    #include <bits/stdc++.h>
    using namespace std;
    int lmax,rmin=INT_MAX,n;
    int main() {
        int x,y;
        scanf("%*d%d",&n);
        for(register int i=1; i<=n; i++) {
            scanf("%d%d",&x,&y);
            lmax=max(lmax,x);
            rmin=min(rmin,y);
        }
        printf("%d\n",max(rmin-lmax+1,0));
        return 0;
    }