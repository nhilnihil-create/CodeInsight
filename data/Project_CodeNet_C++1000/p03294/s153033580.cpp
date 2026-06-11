#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
   int N;
   cin>>N;
   vector<int>A(N);
   int ans=0;
   rep(i,N){
       cin>>A[i];
       ans+=A[i];
   }
   cout<<ans-N<<endl;
}