#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;

int main() {
  int N; cin >> N;
  vector<vector<int>> vec(2, vector<int>(N));
  rep(i,2){
    rep(j,N){
      cin >> vec.at(i).at(j);
    }
  }
  
  int ans=0;
  rep(i,N){
    int ssum = 0;
    rep(j,i+1){
      ssum += vec.at(0).at(j); 
    }
    for (int j=i; j<N; j++){
      ssum += vec.at(1).at(j); 
    }
    ans = max(ans, ssum);
  }
  cout << ans << endl;
  return 0;
}