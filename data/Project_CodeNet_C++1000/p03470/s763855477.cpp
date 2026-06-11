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
   int N;
   cin>>N;
   vector<int>A(N);
   vector<int>K(10000000);
   int ans=0;
   rep(i,N){
       cin>>A[i];
        if(K[A[i]]==0){
            ans++;
            K[A[i]]++;
        }
   }
   cout<<ans<<endl;
}
