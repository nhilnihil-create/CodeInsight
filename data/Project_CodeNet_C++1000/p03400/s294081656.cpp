#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  int N = 0,D = 0,X = 0,ans = 0;
  cin >> N >> D >> X;
  vector<int>A(N);
  rep(i,N){
    cin >> A[i];
    if(D % A[i] == 0){
      ans += D/A[i];
    }
    else{
      ans += D/A[i] + 1;
    }
  }
  cout << ans + X;
}