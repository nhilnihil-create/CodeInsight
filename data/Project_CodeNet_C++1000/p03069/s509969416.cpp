#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  string S;
  cin >> S;

  int left_black = 0, right_white = 0;
  for(int i = 0; i < S.size(); i++){
    if(S[i] == '.'){
      right_white++;
    }
  }
  int ans = 1e9;
  for(int white_end_idx = 0; white_end_idx <= S.size(); white_end_idx++){
    ans = min(ans, left_black + right_white);
    if(white_end_idx < S.size()){
      if(S[white_end_idx] == '#'){
	left_black++;
      }else{
	right_white--;
      }
    }
  }
  cout << ans << endl;
}
