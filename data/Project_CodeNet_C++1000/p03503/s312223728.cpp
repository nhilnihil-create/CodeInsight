        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =200002;
const int MOD =1000000007;


   
     signed main(){
 int n;
 cin>>n;
 int f[n][10];
 for(int i=0;i<n;i++)for(int j=0;j<10;j++)cin>>f[i][j];
 int p[n][11];
 for(int i=0;i<n;i++)for(int j=0;j<11;j++)cin>>p[i][j];
 int ans=-MOD*MOD;
 for(int i=1;i<(1ll<<10);i++){
     int ans2=0;
     for(int j=0;j<n;j++){
         int x=0;
         for(int k=0;k<10;k++)if(bool((1ll<<k)&i)&f[j][k])x++;
         ans2+=p[j][x];
        
     }
     ans=max(ans,ans2);
    
 }
 cout<<ans<<endl;
   }
     


 


 






    





      

        
