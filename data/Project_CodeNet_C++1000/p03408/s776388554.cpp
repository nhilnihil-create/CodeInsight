#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
   int N;
   cin>>N;
   vector<string>S(N);
   rep(i,N){
       cin>>S[i];
   }
   int M;
   cin>>M;
   vector<string>T(M);
   rep(i,M){
       cin>>T[i];
   }
   int ans=0;
   bool h=false;
   rep(i,N){
       int cnt=0;
       rep(j,M){
           if(S[i]==T[j]){
               cnt--;
           }
       }
       rep(j,N){
               if(S[i]==S[j]){
                   cnt++;
               }
           }
       
       if(ans<cnt){
           ans=cnt;
           h=true;
       }
   }
  cout<<ans<<endl;
}