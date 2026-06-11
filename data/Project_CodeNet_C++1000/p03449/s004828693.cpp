#include <bits/stdc++.h>

using namespace std;

int main()
{
   //int t,l=1;
   
   //cin>>t;
   
   //while(t--){
       long long int n;
       cin>>n;
       
       long long a[n],b[n],ans[n],ca[n+1],cb[n+1];
       memset(ans,0,sizeof(ans));
       memset(ca,0,sizeof(ca));
       memset(cb,0,sizeof(cb));
       
       for(long long int i = 0 ; i < n ; i++){
           cin>>a[i];
           ca[i+1] = a[i] + ca[i];
       }
       for(long long int i = 0 ; i < n ; i++){
           cin>>b[i];
           cb[i+1] = b[i] + cb[i];
       }
       
       
       for(long long int i = 1 ; i <= n ; i++){
           ans[i-1] = ca[i] + cb[n] - cb[i-1];
       }
       
       sort(ans,ans+n);
       
       cout<<ans[n-1];
       //l++;
   //}
   
   return 0;

}