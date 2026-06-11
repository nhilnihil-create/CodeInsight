#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<bitset>
#include<queue>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
const int maxn = 100000+10;
const int maxm = 4e5 + 10;
const int inf_max = 0x3f3f3f;
const int mod = 1000000007;
using namespace std;
typedef long long ll;

int main()
{
    int n,tar;
    scanf("%d",&n);
    printf("%d\n",n*(n-1)/2 - n/2);
    if(n % 2) tar = n;
    else tar = n+1;
    for(int i = 1;i <= n; ++i) {
        for(int j = i + 1;j <= n; ++j) {
            if(i + j == tar) continue;
            printf("%d %d\n",i,j);
        }
    }
    return 0;
}