//
//  main.cpp
//  B
//
//  Created by 黄道煜 on 2018/6/24.
//  Copyright © 2018年 黄道煜. All rights reserved.
//

#include <cstdio>
#include <iostream>
#define LL long long
using namespace std;

LL k, n, d=1;

int s(LL x)
{
    int sum=0;
    while(x) sum+=x%10, x/=10;
    return sum;
}

int main()
{
    scanf("%lld", &k);
    for(int i=1; i<=k; i++)
    {
        if((n+d*10)*s(n+d)<(n+d)*s(n+d*10)) d*=10;
        n+=d;
        printf("%lld\n", n);
    }
    return 0;
}
