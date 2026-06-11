#include<cstdio>
#include<algorithm>
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    printf("%d\n",std::max(a*b,std::max(a+b,a-b)));
}