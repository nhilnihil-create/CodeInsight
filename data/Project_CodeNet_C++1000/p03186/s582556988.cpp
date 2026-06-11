#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

int main(){
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if(a+b>=c)
        printf("%lld\n",b+c);
    else
        printf("%lld\n",b*2+a+1);

     return 0;
}
