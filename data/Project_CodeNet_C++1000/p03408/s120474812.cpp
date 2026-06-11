#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin >> N;
  vector<string>blue(N);
  vector<int>bc(N);
  for (int i=0; i<N; i++) cin >> blue.at(i);
  cin >> M;
  vector<string>red(M);
  for (int i=0; i<M; i++) cin >> red.at(i);
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      if(blue.at(i) == blue.at(j)) bc.at(i)++;
    }
  }
  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      if(blue.at(i) == red.at(j)) bc.at(i)--;
    }
  }
  int ans=0;
  for (int i=0; i<N; i++){
    ans = max(bc.at(i), ans);
  }
  cout << ans << endl;
}