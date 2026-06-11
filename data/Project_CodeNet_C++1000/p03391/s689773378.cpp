#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

int main(){
  int N;
  cin >> N;
  vector<i64> A(N),B(N);
  rep(i,0,N - 1){
    cin >> A[i] >> B[i];
  }
  if(A == B){
    cout << 0 << endl;
    return 0;
  }

  i64 ans = 0;
  i64 asdf = 0;
  i64 MIN = 1e18;
  i64 cnt = 0;
  rep(i,0,N - 1){
    if(A[i] <= B[i]){
      ans += B[i];
    }
    else{
      asdf += B[i];
      MIN = min(MIN , B[i]);
      cnt++;
    }
  }
  if(cnt >= 2) ans += asdf - MIN;
  cout << ans << endl;
}