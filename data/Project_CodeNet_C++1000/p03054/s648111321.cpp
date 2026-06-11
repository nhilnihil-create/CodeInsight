#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
int main(){
  int H;
  int W;
  int N;
  cin >> H >> W >> N;
  int sr;
  int sc;
  cin >> sr >> sc;
  string S;
  string T;
  cin >> S;
  cin >> T;

  int right_remove = W + 1;
  int left_remove = 0;
  int up_remove = 0;
  int down_remove = H + 1;
  for(int i = N - 1; i >= 0; i--){
    if(right_remove == W + 1){
      if(S[i] == 'R'){
        right_remove = W;
      }
    } else {
      if(S[i] == 'R' && T[i] != 'L'){
        right_remove --;
      } else if (S[i] != 'R' && T[i] == 'L' && right_remove < W + 1){
        right_remove ++;
      }
    }

    if(left_remove == 0){
      if(S[i] == 'L'){
        left_remove = 1;
      }
    } else {
      if(S[i] == 'L' && T[i] != 'R'){
        left_remove ++;
      } else if(S[i] != 'L' && T[i] == 'R' && left_remove > 0){
        left_remove --;
      }
    }

    if(left_remove + 1 >= right_remove){
      break;
    }


    if(up_remove == 0){
      if(S[i] == 'U'){
        up_remove = 1;
      }
    } else {
      if(S[i] == 'U' && T[i] != 'D'){
        up_remove ++;
      } else if(S[i] != 'U' && T[i] == 'D' && up_remove > 0){
        up_remove --;
      }
    }

    if(down_remove == H + 1 && S[i] == 'D'){
      down_remove = H;
    } else {
      if(S[i] == 'D' && T[i] != 'U'){
        down_remove --;
      } else if(S[i] != 'D' && T[i] == 'U' && down_remove < H + 1){
        down_remove ++;
      }
    }

    if(up_remove + 1 >= down_remove){
      break;
    }
  }

  if(up_remove < sr && sr < down_remove && left_remove < sc && sc < right_remove){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}