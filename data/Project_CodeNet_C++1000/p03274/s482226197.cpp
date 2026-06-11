#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000


signed main()
 {
   int n,k;
   cin>>n>>k;
   vector<int>x(n);
   rep(i,n){cin>>x[i];}
   int m=INF;
   rep(i,n-k+1){
     if((x[i]>=0&&x[i+k-1]>=0)||(x[i]<=0&&x[i+k-1]<=0)){
       m=min(m,max(abs(x[i]),abs(x[i+k-1])));
     }
     else m=min(m,min(2*abs(x[i])+x[i+k-1],abs(x[i])+2*x[i+k-1]));
   }
   cout<<m;
 }
