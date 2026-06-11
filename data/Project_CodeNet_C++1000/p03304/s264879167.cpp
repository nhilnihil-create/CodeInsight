#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,d;
int main() {
    scanf("%lld%lld%lld",&n,&m,&d);
    double d0 = n, d1 = (n-1.0)*2.0;
    if(d==0){
        double ans = 1.0*d0*(m-1.0)/n/n;
        printf("%.8f\n",ans);
    }
    else if(d==1){
        double ans = 1.0*d1*(m-1.0)/n/n;
        printf("%.8f\n",ans);
    }
    else {
        double dd = d1 - 1.0*(d-1.0)*2.0;
        double ans = 1.0*dd*(m-1.0)/n/n;
        printf("%.8f\n",ans);
    }
    return 0;
}