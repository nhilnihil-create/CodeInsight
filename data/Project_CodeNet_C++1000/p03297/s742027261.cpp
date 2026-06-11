#include <iostream>
using namespace std;
typedef long long LL;
int T;
LL a,b,c,d;
LL gcd(LL x, LL y) {
    return y==0?x:gcd(y,x%y);
}
int main() {
    scanf("%d", &T);
    while(T--) {
        cin>>a>>b>>c>>d;
        if(d<b||a<b) {
            printf("No\n"); continue;
        }
        LL a1 = a - ((a-(c+1))/b + 1)*b;
        //printf("a1 = %lld\n", a1);
        if (a1<0) {
            printf("No\n"); continue;
        }
        LL dt = gcd(b,d);
        if(dt==0) {
            printf("Yes\n"); continue;
        }
        LL l = (c+1-a1+dt-1)/dt;
        LL r = (b-1-a1)/dt;
        //printf("[%lld,%lld]\n", l,r);
        if (r >= l) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}

