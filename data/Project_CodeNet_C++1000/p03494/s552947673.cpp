#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, cnt = 100000000, tmp;
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++) cin >> V.at(i);
  for (int i = 0; i < N; i++){
    tmp = 0;
    while(V.at(i) % 2 == 0){
      V.at(i) /= 2;
      tmp++;
    }
    cnt = min(cnt, tmp);
  }
  cout << min(cnt, tmp) << endl;
  return 0;
}