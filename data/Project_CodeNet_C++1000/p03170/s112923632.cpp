#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[101];
bool dp[100001];
bool b(){
    dp[0]=0;
    int i=1;
    while(i<=k){
        bool gh=false;
        int index=0;

       while( index<n && (i-a[index])>=0){
          if(dp[i-a[index]]==0){
              gh=true;
              break;
          }
           index++;
       }
       dp[i]=gh;
       i++;

    }

   return dp[k];
}
int32_t main() {
    cin>>n>>k;  
    memset(dp, 1, sizeof dp);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    if(!b()){
    cout<<"Second";
    }else{
        cout<<"First";
    }
    return 0;
}
