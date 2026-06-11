#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
int main(){
  int N; cin >> N;
  vector<string> S(N); rep(i, N) cin >> S.at(i);
  vector<long long int> MARCH(5, 0);
  rep(i, N){
    if(S.at(i).at(0) == 'M'){
      MARCH.at(0)++;
    } else if(S.at(i).at(0) == 'A'){
      MARCH.at(1)++;
    } else if(S.at(i).at(0) == 'R'){
      MARCH.at(2)++;
    } else if(S.at(i).at(0) == 'C'){
      MARCH.at(3)++;
    } else if(S.at(i).at(0) == 'H'){
      MARCH.at(4)++;
    }
  }
  long long ans = 0;
  for(int i = 0; i < 3; i++){
    for(int j = i+1; j < 4; j++){
      for(int k = j+1; k < 5; k++){
        ans += MARCH.at(i) * MARCH.at(j) * MARCH.at(k);
      }
    }
  }
  cout << ans << endl;
  return 0;
}