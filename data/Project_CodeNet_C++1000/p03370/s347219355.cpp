#include <bits/stdc++.h>
using namespace std;
int main()
{
       int n,x,sum=0;
       cin>>n>>x;
       int arr[n];
       for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
       }
      int* m=min_element(arr,arr+n);
       sum=x-sum;
       cout<<n+(sum/ *m);
    return 0;
   }