#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <set>
using namespace std;
#define maxn 100000+5
typedef long long int ll;
const double INF = 1e20;
const double pi = acos (-1.0);
int vis[5];
int main () {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    printf("%d ",min(a,b));
    if(a+b<=n)printf("0");
    else printf("%d",a+b-n);
   //while(1)getchar();
    return 0;
}
