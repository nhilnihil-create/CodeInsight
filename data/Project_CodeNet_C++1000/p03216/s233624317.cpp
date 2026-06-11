#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin >> N;
  string S;
  cin >> S;
  int64_t Q;
  cin >> Q;
  vector<int64_t> query(Q);
  for(int i=0; i<Q; i++){
    cin >> query[i];
    query[i]--;
  }
  vector<int64_t> ans(Q);
  vector<vector<int64_t>> DM(Q,vector<int64_t>(3,0)); //Dの数、Mの数、DMの数
  for(int i=0; i<N; i++){
    if(S[i] == 'D'){
      for(int j=0; j<Q; j++){
        DM[j][0]++;
      }
    }
    if(S[i] == 'M'){
      for(int j=0; j<Q; j++){
        DM[j][1]++;
        DM[j][2] += DM[j][0];
      }
    }
    if(S[i] == 'C'){
      for(int j=0; j<Q; j++){
        ans[j] += DM[j][2];
      }
    }
    for(int j=0; j<Q; j++){
      if(i - query[j] >= 0){
        int x = i - query[j];
        if(S[x] == 'D'){
          DM[j][0]--;
          DM[j][2] -= DM[j][1];
        }
        if(S[x] == 'M'){
          DM[j][1]--;
        }
      }
    }
  }
  
  for(int i=0; i<Q; i++){
    cout << ans[i] << endl;
  }
}