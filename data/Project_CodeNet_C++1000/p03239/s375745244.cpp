#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  int n,T;
  cin >> n >> T;
  vector<int> c(n);
  vector<int> t(n);
  rep(i,n){
    cin >> c[i] >> t[i];
  }
  int ans=1001;
  rep(i,n){
    if(t[i]<=T){
      if(ans>c[i]){
        ans = c[i];
      }
    }
  }
  if(ans==1001){
    cout << "TLE" << endl;
  }else{
    cout << ans << endl;
  }
}
