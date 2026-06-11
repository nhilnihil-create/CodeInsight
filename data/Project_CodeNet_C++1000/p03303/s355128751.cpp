#include<bits/stdc++.h>
using namespace std;
int main()
{

     char str[2000];
     scanf("%s",str);
     int n;
     scanf("%d",&n);
     int l = strlen(str);

     for(int i=0; i<l; i++)
     {
       if(i==0)
       {
         printf("%c",str[i]);
         continue;
       }
       if(i%n==0)
       {
         printf("%c",str[i]);
       }
     }
     printf("\n");

}
