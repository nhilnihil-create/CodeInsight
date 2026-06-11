#include <bits/stdc++.h>
using namespace std;
int main () {
  long N, K;
  cin >> N >> K;
  vector<pair<long, long>> data(N);
  vector<long> x(N), y(N);
  for(int i = 0; i < N; i++){
    cin >> data.at(i).first >> data.at(i).second;
    x.at(i) = data.at(i).first;
    y.at(i) = data.at(i).second;
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  long ans = ((long)1000000000 * 2) * ((long)1000000000 * 2) + 1;
  long count;
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      if(x.at(i) == x.at(j))continue;
      for(int k = 0; k < N; k++){
        for(int l = k + 1; l < N; l++){
          if(y.at(k) == y.at(l))continue;
          count = 0;
          for(int m = 0; m < N; m++){
            if(x.at(i) <= data.at(m).first && x.at(j) >= data.at(m).first){
              if(y.at(k) <= data.at(m).second && y.at(l) >= data.at(m).second){
                count++;
              }
            }
            if(count >= K)ans = min(ans, (x.at(j) - x.at(i)) * (y.at(l) - y.at(k)) );
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}