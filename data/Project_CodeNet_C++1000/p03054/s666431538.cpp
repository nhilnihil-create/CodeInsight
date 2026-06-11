#include<bits/stdc++.h>

using namespace std;

int main(){
  int H, W, N; cin >> H >> W >> N;
  
  int sr, sc; cin >> sr >> sc; --sr; --sc;
  
  string S, T; cin >> S >> T;
  
  int left = 0, right = W, up = 0, down = H;
  
  for(int i = N - 1; i >= 0; --i){
    if(T[i] == 'L'){
      right = min(right + 1, W);
    }else if(T[i] == 'R'){
      left = max(left - 1, 0);
    }else if(T[i] == 'U'){
      down = min(down + 1, H);
    }else{
      up = max(up - 1, 0);
    }
    
    if(S[i] == 'L'){
      ++left;
    }else if(S[i] == 'R'){
      --right;
    }else if(S[i] == 'U'){
      ++up;
    }else{
      --down;
    }
    
    if(left == right || up == down) break;
  }
  
  if(up <= sr && sr < down && left <= sc && sc < right) puts("YES");
  else puts("NO");
  
  return 0;
}