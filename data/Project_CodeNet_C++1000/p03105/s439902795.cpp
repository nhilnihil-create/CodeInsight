#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
int ans;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    ans=b/a;
    ans=min(ans,c);
    printf("%d\n",ans);
    return 0;
}
