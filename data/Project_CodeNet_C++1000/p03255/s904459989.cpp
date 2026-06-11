//
//  main.cpp
//  B
//
//  Created by 黄道煜 on 2018/9/22.
//  Copyright © 2018年 黄道煜. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL unsigned long long
using namespace std;

int n;
LL x, a[200005], ans=1e18;

int main()
{
    scanf("%d%lld", &n, &x);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]), a[i]+=a[i-1];
    for(int i=1, j; i<=n; i++)
    {
        LL temp=2*(a[n]-a[n-i])+(n+i)*x;
        for(j=1; i*j<=n; j++) temp+=(a[n-i*(j-1)]-a[n-i*j])*(2*j+1);
        temp+=a[n-i*j+i]*(2*j+1);
        ans=min(ans, temp);
    }
    printf("%lld\n", ans);
}
