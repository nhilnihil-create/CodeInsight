#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int A,B,C,X,Y,price=0, minprice=999999999999999999;

    scanf("%lld%lld%lld%lld%lld", &A,&B,&C,&X,&Y);


    if (Y>=X) {
        for (long long int i=0;i<X*2;i++) price+=C;
        for (long long int i=0;i<Y-X;i++) price+=B;
    } else {
        for (long long int i=0;i<Y*2;i++) price+=C;
        for (long long int i=0;i<X-Y;i++) price+=A;
    }
    minprice=min(price, minprice);
    price=0;

    for (long long int i=0;i<X;i++) price+=A;
    for (long long int i=0;i<Y;i++) price+=B;

    minprice=min(price, minprice);
    price=0;

    for (long long int i=0;i<max(X,Y)*2;i++) price+=C;

    minprice=min(price, minprice);
    price=0;

    printf("%lld", minprice);
}