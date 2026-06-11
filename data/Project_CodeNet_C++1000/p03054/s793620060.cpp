#include<iostream>
using namespace std;

int main(){
  int H, W, N;
  cin >> H >> W >> N;

  int s_r, s_c;
  cin >> s_r >> s_c;

  string S, T;
  cin >> S >> T;

  int safe_h_begin = 1, safe_h_end = H + 1,
    safe_w_begin = 1, safe_w_end = W + 1;
  for(int i = N - 1; i >= 0; i--){
    // S[i], T[i - 1]
    if(S[i] == 'L'){
      safe_w_begin++;
    }else if(S[i] == 'R'){
      safe_w_end--;
    }else if(S[i] == 'U'){
      safe_h_begin++;
    }else{
      safe_h_end--;
    }
    if(safe_w_end <= safe_w_begin || safe_h_end <= safe_h_begin){
      cout << "NO" << endl;
      return 0;
    }

    if(i > 0){
    if(T[i - 1] == 'L'){
      safe_w_end = min(W + 1, safe_w_end + 1);
    }else if(T[i - 1] == 'R'){
      safe_w_begin = max(1, safe_w_begin - 1);
    }else if(T[i - 1] == 'U'){
      safe_h_end = min(H + 1, safe_h_end + 1);
    }else{
      safe_h_begin = max(1, safe_h_begin - 1);
    }
    }
    
  }

  //cout << safe_h_begin << ' ' << s_r << ' ' << safe_h_end << endl;
  //cout << safe_w_begin << ' ' << s_c << ' ' << safe_w_end << endl;
  if(s_r >= safe_h_begin && s_r < safe_h_end && s_c >= safe_w_begin && s_c < safe_w_end){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

