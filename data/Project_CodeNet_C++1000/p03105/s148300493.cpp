#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
   int a,b,c;
   scanf("%d%d%d",&a,&b,&c);
   if(a*c<=b)printf("%d\n",c);
   else
   {
       printf("%d\n",(int)(b/a));
   }
    return 0;
}
