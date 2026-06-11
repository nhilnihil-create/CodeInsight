#include <bits/stdc++.h>
using namespace std;
int main(){
   int i,j,k,n;
   cin >> n >>k;
   int arr[n];
   for(i=0;i<n;++i){
    cin >> arr[i];
   }
   int win[k+2];
   for(i=1;i<=k;++i){
    for(j=0;j<n;++j){
        if(i == arr[j]){
            win[i]=1;
            break;
        }
        if(i-arr[j]>=1 && win[i-arr[j]]!=1){
            win[i]=1;
            break;
        }
    }
    if(j==n)
        win[i]=0;
   }
   if(win[k])
    cout <<"First"<<endl;
   else
    cout <<"Second"<<endl;
  return 0;


}
