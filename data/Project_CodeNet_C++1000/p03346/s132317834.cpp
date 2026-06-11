//AGC Backfront
#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  vector<int> pos(N);
  for(int i=0; i<N; i++){
    int x = vec.at(i);
    pos.at(x-1) = i;
  }
  int ans = 0;
  int j = 0;
  int j_pos = -1;
  int cnt = 0;
  while(j < N){
    if(j_pos == -1){
      j_pos = pos.at(j);
      j++;
      cnt++;
      continue;
    }
    else{
      if(pos.at(j) > j_pos){
        j_pos = pos.at(j);
        j++;
        cnt++;
        continue;
      }
      else{
        ans = max(ans,cnt);
        cnt = 0;
        j_pos = -1;
        continue;
      }
    }
  }
  ans = max(ans,cnt);
  cout << N - ans << endl;
}