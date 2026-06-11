#include <cstdio>
#include <algorithm>
using namespace std;
long long v[200005],msum[200005];
int main() {
    int n;
    long long x;
    scanf("%d%lld",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        msum[i]+=v[i]+msum[i-1];
    }
    long long ans=100000000000000000;
    for(int k=1;k<=n;k++){
        long long ff=0;
        for(int j=1,r=n,l=0;r>0&&ff+k*x<ans;r=l-1,j++){
            l=(r-k+1)>1?(r-k+1):1;
            ff+=(j==1?5:(j*2+1))*(msum[r]-msum[l-1]);
        }
        ans=min(ff+k*x,ans);
    }
    printf("%lld\n",ans+n*x);
    return 0;
}
