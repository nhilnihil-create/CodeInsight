#include<bits/stdc++.h>
#define endl '\n'
#define PI 3.14159265358979323844
#define DECIMAL(n)  std::cout << std::fixed;std::cout << std::setprecision(n);
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define int long long int 
#define forr(i,a,b) for (int i= a; i <b; ++i)
using namespace std; 
 signed main(){
 int n;cin>>n;
  int a[n];
  int b[n];
  forr(i,0,n)cin>>a[i];
    forr(i,0,n)cin>>b[i];
  int dp[n];
  memset(dp,0,sizeof dp);
  map<int,int> mean;
  mean[a[0]]=b[0];
  dp[0]=b[0];
  forr(i,1,n){
      dp[i]=b[i];
   auto it = mean.lower_bound(a[i]+1);
        if(it!=mean.begin())   
        {   it--;
            dp[i]+=(it->second);
        }
       mean[a[i]]= dp[i];
      it = mean.upper_bound(a[i]);
      
      while(it!=mean.end() &&it->second<=dp[i]){
          auto temp=it;
          temp++;
          mean.erase(it);
           it=temp;
      }
  }
  int maxx=0;
  forr(i,0,n)maxx=max(maxx,dp[i]);
 cout<<maxx;}