#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main()
{
   int arr[5];
   for(int i=0;i<5;i++)
      cin>>arr[i];
   int k;
   int flag = 0;
   cin>>k;
   for(int i=0;i<4;i++)
   {
      for(int j=i+1;j<5;j++)
      {
         if(arr[j] - arr[i]>k)
         {
            flag = 1;
            break;
         }

      }
   }
   if(flag == 0)
      cout<<"Yay!";
   else
      cout<<":(";
   return 0;
}
