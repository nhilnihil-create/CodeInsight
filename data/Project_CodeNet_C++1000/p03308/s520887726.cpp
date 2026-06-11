#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b){
  return abs(a-b);
}

int main(){
  int N,ans=0; cin >> N;
  vector<int> a(N);
  for(int i=0; i<N; i++) cin >> a.at(i);

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      ans = max({ans,solve(a.at(i),a.at(j))});
    }
  }
  cout << ans << endl;
}
