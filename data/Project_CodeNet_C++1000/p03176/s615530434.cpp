#include<bits/stdc++.h>
using namespace std ; 
long long int dp[20005];  

//this is lis ka hee modifcation and this is an o(n^2) solution. 
// this will give tle as n-> 10^5. //therefire we need to have  o(nlogn)solutioon
long long int solve(int n,long long int h[],long long int b[]){
   dp[1] = b[1] ; //max sum of beauties of a subseq ending at 1.  
   for(int i = 2 ; i<=n  ;i++){
       dp[i] =b[i] ;
   }
   for(int i= 2 ; i<=n; i++)
{   
    for(int j = 1; j<=i-1; j++){
     if(h[i]>h[j]){
         dp[i] = max(dp[i],b[i]+dp[j]) ; 
     }   
    }
} 
 return *max_element(dp+1,dp+n+1) ; 
}

//o(nlogn) 
struct flower{
    long long int h ; long long int b ; 
};
long long solve_better(vector<flower>& v,int n){
       vector<long long > dp(n+1); 
       map<long long int,long long int>meaningful ; 
       dp[1] = v[1].b ;  
       meaningful[v[1].h] = dp[1] ; //inserted into the map . 
      long long int ans  = dp[1];
      for(long long int i = 2 ; i<=n; i++){
            dp[i] = v[i].b ; 
            auto it = meaningful.lower_bound(v[i].h + 1) ; 
            if(it!=meaningful.begin()){
               it-- ; 
               dp[i] += it->second ; 
            }
            meaningful[v[i].h] = dp[i] ; 
           
           auto it2 = meaningful.upper_bound(v[i].h) ; 
           while(it2!=meaningful.end() && it2->second<=dp[i]){
               auto temp = it2 ; 
               temp++ ; 
               meaningful.erase(it2) ; 
               it2 = temp ; 
           }
          ans = max(ans,dp[i]) ; 
       }

return ans ; 

}
int main(){
    long long int n ; cin>>n ; 
    vector<flower> v(n+1);
    for(int i = 1 ; i<=n ; i++){
        cin>>v[i].h ;
    }
    for(int i = 1 ; i<=n ; i++){
        cin>>v[i].b  ; 
    }
    cout<<solve_better(v,n); 
}