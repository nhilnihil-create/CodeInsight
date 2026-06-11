#include <iostream>
#include<algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <deque>
#include <stack>
using namespace std;
const int N=1e5+10;
int a[N];
int main()
{

   int a,b,c;
   int ans;
   scanf("%d %d %d",&a,&b,&c);
   if(a>b)
   {
       printf("0\n");
   }
   else
   {
       ans=b/a;
       if(ans>=c)
       {
           printf("%d\n",c);
       }
       else
        printf("%d\n",ans);
   }

    return 0;
}
