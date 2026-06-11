#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<vector<char>> vec(Q,vector<char>(2));
  for(int i=0; i<Q; i++){
    for(int j=0; j<2; j++){
      cin >> vec[i][j];
    }
  }
  
  int ans = 0;
  
  //左側に落ちるかどうか
  int ok = -1;
  int ng = N;
  int mid = (ok+ng)/2;
  while(ng - ok > 1){
    mid = max(0,(ok+ng)/2);
    char pos_c = S[mid];
    int pos = mid;
    bool out = false;
    for(int i=0; i<Q; i++){
      if(vec[i][0] == pos_c){
        if(vec[i][1] == 'L'){
          if(pos == 0){
            out = true;
            break;
          }
          else{
            pos--;
            pos_c = S[pos];
          }
        }
        else{
          if(pos == N-1){
            break;
          }
          else{
            pos++;
            pos_c = S[pos];
          }
        }
      }
    }
    if(out){
      ok = mid;
    }
    else{
      ng = mid;
    }
  }
  
  
  int A = ok;
  
  //右側に落ちるかどうか
  
  ok = N;
  ng = -1;
  mid = (ok+ng)/2;
  while(ok - ng > 1){
    mid = min(N-1,(ok+ng)/2);
    char pos_c = S[mid];
    int pos = mid;
    bool out = false;
    for(int i=0; i<Q; i++){
      if(vec[i][0] == pos_c){
        if(vec[i][1] == 'L'){
          if(pos == 0){
            break;
          }
          else{
            pos--;
            pos_c = S[pos];
          }
        }
        else{
          if(pos == N-1){
            out = true;
            break;
          }
          else{
            pos++;
            pos_c = S[pos];
          }
        }
      }
    }
    if(out){
      ok = mid;
    }
    else{
      ng = mid;
    }
  }
  
  int B = ok;
  
  
  cout << max(0, B - A - 1) << endl;
}
  
          