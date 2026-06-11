#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<string> S(H + 2, ".");
  
  for (int i = 0; i < W + 1; i++){
    S.at(0) += ".";
    S.at(H + 1) += ".";
  }

  
  for (int i = 1; i <= H; i++){
    string s;
    cin >> s;
    S.at(i) += s;
    S.at(i) += ".";
  }
  
  for (int i = 1; i <= H; i++){
    for (int j = 1; j <= W; j++){
      int num = 0;
      if (S.at(i).at(j) == '#'){
        continue;
      }
      
      if (S.at(i - 1).at(j - 1) == '#'){
        num++;
      }
      if (S.at(i - 1).at(j) == '#'){
        num++;
      }
      if (S.at(i - 1).at(j + 1) == '#'){
        num++;
      }
      if (S.at(i).at(j - 1) == '#'){
        num++;
      }
      if (S.at(i).at(j + 1) == '#'){
        num++;
      }
      if (S.at(i + 1).at(j - 1) == '#'){
        num++;
      }
      if (S.at(i + 1).at(j) == '#'){
        num++;
      }
      if (S.at(i + 1).at(j + 1) == '#'){
        num++;
      }
      
      S.at(i).at(j) = num + 48;
    }
  }
  
  for (int i = 1; i <= H; i++){
    for (int j = 1; j <= W; j++){
      cout << S.at(i).at(j);
    }
    cout << endl;
  }

}