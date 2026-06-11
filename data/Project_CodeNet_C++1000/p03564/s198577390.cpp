#include <stdio.h>
 
int main()
{
   int n, k, ans=1;
   
   scanf("%d %d", &n, &k);
   
   for(int i=0 ; i<n ; i++){
   	(ans+k > ans*2) ? ans*=2 : ans+=k;
   }
   
   printf("%d", ans);
   
   return 0;
}