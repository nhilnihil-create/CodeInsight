#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
   ll N;
   cin>>N;
   vector<ll>A(N);
   ll ans=1;
   ll q=1;
   rep(i,N){
       cin>>A[i];
       ans*=3;
       if(A[i]%2==1){
           q*=1;
       }
       else{
           q*=2;
       }
   }
   cout<<ans-q<<endl;
}
