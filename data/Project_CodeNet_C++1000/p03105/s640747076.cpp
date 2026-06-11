#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()

{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        printf("%d\n",b/a>c?c:b/a);
    }

}
