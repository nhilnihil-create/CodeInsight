#include <cstdio>
#define LL long long
using namespace std;
LL get(LL x){
    LL ans=0;
    while (x){ans+=x%10;x/=10;}
    return ans;
}
int main() {
    LL k;
    scanf("%lld",&k);
    LL x=1,p=1;
    while (k--){
        printf("%lld\n",x);
        LL nx1=x+p;
        LL nx2=x+10*p;
        if (nx1*get(nx2)<=nx2*get(nx1)) x = nx1;
        else {x=nx2;p*=10;}
    }
    return 0;
}
