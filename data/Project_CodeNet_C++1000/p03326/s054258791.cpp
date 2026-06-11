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
   vector<int>y(n);
   vector<int>z(n);
   vector<int>s(n);
   rep(i,n){
     cin>>x[i]>>y[i]>>z[i];
   }
   int M=0;
   for(int i=0;i<=7;i++){
     int a,b,c;
     a=i%2;
        c=i/4;
     b=(i-a-c*4)/2;

     rep(i,n){
       s[i]=x[i]*pow(-1,a)+y[i]*pow(-1,b)+z[i]*pow(-1,c);
     }
     sort(s.begin(),s.end());
     int tmp=0;
     for(int i=n-k;i<=n-1;i++){
       tmp+=s[i];
     }
   M=max(M,tmp);
 }
 cout<<M;
}
