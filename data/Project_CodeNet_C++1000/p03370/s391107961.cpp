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
int main(){
 int n,x;
  cin>>n>>x;
  int p=0;
  vector<int>A(n);
  rep(i,n){
   cin>>A[i];
p+=A[i];}
  x-=p;
  sort(A.begin(),A.end());
  n+=x/A[0];
  cout<<n<<endl;
}


