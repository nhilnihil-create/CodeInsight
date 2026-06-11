#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<int> P(N);
  vector<int> Q(N);
  for(int i = 0; i < N; i++){
    cin >> P[i];
    Q[P[i] - 1] = i;
  }
  
  int cnt = 1;
  int max_cnt = 1;
  for(int i = 1; i < N; i++){
    if(Q[i - 1] < Q[i]) cnt++;
    else{
      max_cnt = max(cnt, max_cnt);
      cnt = 1;
    }
  }
  max_cnt = max(cnt, max_cnt);
  
  cout << N - max_cnt << endl;
  
  return 0;
}