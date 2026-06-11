#include<stdio.h>

int main()

{
   int a[10],n,b,c,i,j,k,z,sum=0,temp;

   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }

   for(j=0;j<n;j++)
   {
      for(k=j+1;k<n;k++)
      {
         if(a[k]>a[j])
         {
            temp = a[j];

            a[j] = a[k];

            a[k] = temp;
         }
      }
   }

   for(z=0;z<n;z++)
   {
      if(z==0)
      {
         sum = sum + (a[z]/2);
      }

      else
      {
         sum = sum + a[z];
      }
   }

   printf("%d\n",sum);
}
