#include<bits/stdc++.h>
#define N 1000000007
#include<fstream>
using namespace std;
vector<vector<long>>adj;
vector<vector<long>>adjf;
map<long,bool>vis,viss;
map<pair<long,long>,bool>f;
map<long,long>aa,bb,cc;
unsigned long long power(unsigned long long x, 
                         long long y, long long p) 
{ 
    unsigned long long res = 1; // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
unsigned long long modInverse(unsigned long long n, long long p) 
{ 
    return power(n, p - 2, p); 
} 

unsigned long long ncrmp(unsigned long long n, 
                                 long long int r, long long int p) 
{ 
    // Base case 
    if (r == 0) 
        return 1; 
  
    
    unsigned long long fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 
int main(){
 
      
  long n; double t;
  cin>>n;
  vector<double>p;
  for(long i=0;i<n;i++){cin>>t; p.push_back(t);}
  
  double dp[n+1][n+1];        //dp[i][j] is getting j heads considering first i coins
  for(long i=1;i<=n;i++){
      dp[0][i]=0;    //as we cant get non zero number of heads without considering any elemnt  
      
  }
  dp[0][0]=1; //imp

  for(long i=1;i<n;i++){
     dp[i][0]=dp[i-1][0]*(1-p[i-1]); 
      
  }
  for(long i=1;i<=n;i++){
      for(long j=1;j<=n;j++){
          dp[i][j]=dp[i-1][j]*(1-p[i-1])+dp[i-1][j-1]*p[i-1];
      }
  }
  double ans=0;
  for(long i=(n+1)/2;i<=n;i++){
      ans=ans+dp[n][i];
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
     return 0;                               
}
