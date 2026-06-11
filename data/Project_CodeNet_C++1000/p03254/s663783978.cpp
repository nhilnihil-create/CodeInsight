#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  int N = 0,x = 0,ans = 0;
  cin >> N >> x;
  vector<int>A(N);
  rep(i,N){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  rep(i,N){
    x -= A[i];
    ans++;
    if(x < 0){
      cout << ans - 1;
      return 0;
    }
  }
  if(x != 0){
    cout << N - 1;
  }
  else{
    cout << N;
  }
}