#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
  int N, M;

  cin >> N >> M;
  G A(M, vector<int>(2, 0));

  for( int i=0; i<M; i++){
    for( int j=0; j<2; j++){
      cin >> A.at(i).at(j);
    }    
  }

  int maxL = 1;
  int minR = N;

  rep(i, M){
    maxL = max(maxL, A.at(i).at(0));
    minR = min(minR, A.at(i).at(1));
  }
  int ans = minR - maxL + 1;
  ans = max(ans, 0);
  cout << ans << endl;
}
