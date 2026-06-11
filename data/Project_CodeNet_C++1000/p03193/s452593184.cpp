#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

int main(){
    int n, res=0;
    ll h, w, a, b;
     scanf("%lld%lld%lld", &n, &h, &w);
     for(int i=1; i<=n; i++){
       scanf("%lld%lld", &a, &b);
       if(a>=h&&b>=w)
        res++;
     }
     printf("%d", res);
     return 0;
}
