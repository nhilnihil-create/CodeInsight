#include <iostream>
using namespace std;
typedef long long LL;
const int N = 172;
LL dt[N];
int k;
int s(LL x){
    int sum=0; 
    while(x) sum+=x%10, x/=10;
    return sum; 
}

int main() {
    dt[0]=0;
    LL x=1;
    for(int i=1;i<N;i++) {
        dt[i]=dt[i-1]+x;
        if(i!=1 && (i-10)%9==0) x=x*10LL;
    }
    cin>>k;
    LL now = 1;
    for(int i=1;i<=k;i++) {
        printf("%lld\n", now);
        double mn=1e16; int bst=-1;
        for(int j=1;j<N;j++) {
            double tmp = 1.0*(now+dt[j])/s(now+dt[j]);
            if(tmp<mn) mn=tmp, bst=j;
        }
        now=now+dt[bst];
    }
}