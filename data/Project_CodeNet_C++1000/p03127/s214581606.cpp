#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
   int N;
   cin>>N;
   vector<int>A(N);
   int ans;
   rep(i,N){
       cin>>A[i];
       if(i==0){
           ans=A[0];
       }
       else{
           ans=__gcd(ans,A[i]);
           if(ans==1){
               break;
           }
       }
   }
   cout<<ans<<endl;
}
