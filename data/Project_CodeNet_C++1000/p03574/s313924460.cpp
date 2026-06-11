#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string Long, Short;
  for (int i = 1; i <= W + 2; i++){
    Short += '.';
  }
  for (int i = 1; i <= H; i++){
    string S;
    cin >> S;
    Long += '.' + S + '.';
  }
  Long = Short + Long + Short;
  for (int k = 3 + W; k < (H + 1) * (W + 2) - 1; k++){
    if (k % (W + 2) == W + 1 || k % (W + 2) == 0){
      continue;
    }
    else {
      if (Long.at(k) == '.'){
      if (Long.at(k - (W + 2) - 1) != '#' && Long.at(k - (W + 2)) != '#' && Long.at(k - (W + 2) + 1) != '#' && Long.at(k - 1) != '#' && Long.at(k + 1) != '#' && Long.at(k + (W + 2) - 1) != '#' && Long.at(k + (W + 2)) != '#' && Long.at(k + (W + 2) + 1) != '#'){
        Long.at(k) = '0';
      }
      if (Long.at(k - (W + 2) - 1) == '#'){
        Long.at(k) = '1';
      }//最初の爆弾
      if (Long.at(k - (W + 2)) == '#'){
        if (Long.at(k) == '.'){
          Long.at(k) = '1';
        }
        else if (Long.at(k) == '1'){
          Long.at(k) = '2';
        }
      }//2個目の爆弾
      if (Long.at(k - (W + 2) + 1) == '#'){
        if (Long.at(k) == '.'){
          Long.at(k) = '1';
        }
        else if (Long.at(k) == '1'){
          Long.at(k) = '2';
        }
        else if (Long.at(k) == '2'){
          Long.at(k) = '3';
        }
      }//3個目の爆弾
      if (Long.at(k - 1) == '#'){
        if (Long.at(k) == '.'){
          Long.at(k) = '1';
        }
        else if (Long.at(k) == '1'){
          Long.at(k) = '2';
        }
        else if (Long.at(k) == '2'){
          Long.at(k) = '3';
        }
        else if (Long.at(k) == '3'){
          Long.at(k) = '4';
        }
      }//4個目の爆弾
      if (Long.at(k + 1) == '#'){
        if (Long.at(k) == '.'){
          Long.at(k) = '1';
        }
        else if (Long.at(k) == '1'){
          Long.at(k) = '2';
        }
        else if (Long.at(k) == '2'){
          Long.at(k) = '3';
        }
        else if (Long.at(k) == '3'){
          Long.at(k) = '4';
        }
        else if (Long.at(k) == '4'){
          Long.at(k) = '5';
        }
      }//5個目の爆弾
      if (Long.at(k + (W + 2) - 1) == '#'){
        if (Long.at(k) == '.'){
          Long.at(k) = '1';
        }
        else if (Long.at(k) == '1'){
          Long.at(k) = '2';
        }
        else if (Long.at(k) == '2'){
          Long.at(k) = '3';
        }
        else if (Long.at(k) == '3'){
          Long.at(k) = '4';
        }
        else if (Long.at(k) == '4'){
          Long.at(k) = '5';
        }
        else if (Long.at(k) == '5'){
          Long.at(k) = '6';
        }
      }//6個目の爆弾
      if (Long.at(k + (W + 2)) == '#'){
        if (Long.at(k) == '.'){
          Long.at(k) = '1';
        }
        else if (Long.at(k) == '1'){
          Long.at(k) = '2';
        }
        else if (Long.at(k) == '2'){
          Long.at(k) = '3';
        }
        else if (Long.at(k) == '3'){
          Long.at(k) = '4';
        }
        else if (Long.at(k) == '4'){
          Long.at(k) = '5';
        }
        else if (Long.at(k) == '5'){
          Long.at(k) = '6';
        }
        else if (Long.at(k) == '6'){
          Long.at(k) = '7';
        }
      }//7個目の爆弾
      if (Long.at(k + (W + 2) + 1) == '#'){
        if (Long.at(k) == '.'){
          Long.at(k) = '1';
        }
        else if (Long.at(k) == '1'){
          Long.at(k) = '2';
        }
        else if (Long.at(k) == '2'){
          Long.at(k) = '3';
        }
        else if (Long.at(k) == '3'){
          Long.at(k) = '4';
        }
        else if (Long.at(k) == '4'){
          Long.at(k) = '5';
        }
        else if (Long.at(k) == '5'){
          Long.at(k) = '6';
        }
        else if (Long.at(k) == '6'){
          Long.at(k) = '7';
        }
        else if (Long.at(k) == '7'){
          Long.at(k) = '8';
        }
      }//8個目の爆弾
    }
    }
  }
    for (int k = 3 + W; k < (H + 1) * (W + 2) - 1; k++){
    if (k % (W + 2) == W + 1){
      cout << endl;
    }
    else if (k % (W + 2) == 0){
      continue;      
    }
    else {
      cout << Long.at(k);
    }
  }  
}