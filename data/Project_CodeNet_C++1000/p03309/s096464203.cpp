#include <bits/stdc++.h>
using namespace std;
#define int     long long int

int32_t main() {

    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum=0;
    for(int i=0;i<n;i++){
        arr[i]=(arr[i]-(i+1));
        // sum+=arr[i];
    }

   sort(arr,arr+n);
   int val=(arr[n/2]);

   for(int i=0;i<n;i++){
        sum+=abs(arr[i]-val);
   }
   cout<<sum<<endl;

    return 0;
}