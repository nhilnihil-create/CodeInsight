#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)
#define sc2(a,b)  scanf("%d %d",&a,&b)


int main(){
    int mod=1000000007;
    int n,k;
    sc2(n,k);
    double ans=0.0;
    for (int i=1;i<=n;i++) {
        int x=i,f=1;
        for(;;) {
            if (x>=k) break;
            x*=2;
            f*=2;
        }
        ans+=1.0/(n*f);
    }
    printf("%.15lf\n",ans);
    return 0;
}
