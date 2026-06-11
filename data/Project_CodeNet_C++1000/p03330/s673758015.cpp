#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000


signed main()
 {
   int n,c;
   cin>>n>>c;
   int d[c][c];
   int iro[n][n];
   rep(i,c){
     rep(j,c){
       cin>>d[i][j];
     }
   }
   rep(i,n){
     rep(j,n){
       cin>>iro[i][j];
     }
   }

   int mod1[c],mod2[c],mod0[c];
   rep(i,c){
     mod1[i]=0;
     mod2[i]=0;
     mod0[i]=0;
   }
   rep(i,n){
     rep(j,n){
       if((i+j)%3==0){
         mod0[iro[i][j]-1]++;
       }
       else if((i+j)%3==1){
         mod1[iro[i][j]-1]++;
       }
       else mod2[iro[i][j]-1]++;
     }
   }
int ans=INF;
   rep(i,c){
     rep(j,c){
       rep(k,c){
         if(i==j||j==k||i==k){continue;}
         int iwa=0;
         rep(l,c){
           iwa+=d[l][i]*mod0[l];
         }
         rep(l,c){
           iwa+=d[l][j]*mod1[l];
         }
         rep(l,c){
           iwa+=d[l][k]*mod2[l];
         }
         ans=min(iwa,ans);
       }
     }
   }
   cout<<ans;


 }
