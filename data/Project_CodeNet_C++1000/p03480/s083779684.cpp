#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
   char s[2000005];
   scanf("%s",s+1);
   int l=strlen(s+1);
   int n=l;
   for(int i=1;i<l;i++)
   {
       if(s[i]!=s[i+1])
       {
           n=min(n,max(i,l-i));
       }
   }
   cout<<n<<endl;
    return 0;
}
