#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;++i)
         scanf("%d",&a[i]);
  
    int cnt1=0,cnt2=0;
    for(i=0;i<n-1;++i)
    {
      if(a[i]==a[i+1])
        {cnt1++;
          i++;
        }
      
    }
  
   for(i=n-1;i>=0;--i)
   {
      if(a[i]==a[i-1])
      {
        cnt2++;
        i--;
      }
   }
  
   if(cnt1>=cnt2)
       printf("%d",cnt2);
  
  else
     printf("%d",cnt1);
    
	return 0;
}