#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
   int N,A,B;
   cin>>N>>A>>B;
   int ans=0;
   rrep(i,N){
       bool a=true;
       int cnt=0;
       int j=i;
       while(a==true){
           if(j==0){
               a=false;
           }
           else{
               cnt+=j%10;
               j-=j%10;
               j/=10;
           }
       }
       if(A<=cnt&&cnt<=B){
           ans+=i;
       }
   
   }
   cout<<ans<<endl;
}
