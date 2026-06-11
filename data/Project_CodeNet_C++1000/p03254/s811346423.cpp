#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
   int N,X;
   cin>>N>>X;
   vector<int>A(N);
   rep(i,N){
       cin>>A[i];
   }
   sort(A.begin(),A.end());
   int ans=0;
   rep(i,N){
       if(A[i]<=X){
           ans++;
           X-=A[i];
           if(X!=0&&i+1==N){
               ans--;
           }
       }
       else{
           break;
       }
   }
   cout<<ans<<endl;
}