#include<bits/stdc++.h>
using namespace std;
int main(){
    int Q;
    long long a,b;
    scanf("%d",&Q);
    while(Q--){
        scanf("%lld%lld",&a,&b);
        if(a>b)swap(a,b);
        long long ans=0,c=a*b,d=sqrt(c);
        if(d*d==c)d--;
        if(a==b||a==b+1)ans=2*a-2;
        else if(d*(d+1)>=a*b)ans=2*d-2;
        else ans=2*d-1;
       	printf("%lld\n",ans);
    }
    return 0;
}