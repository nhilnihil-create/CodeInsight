#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  char S[H][W];
  for (int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      cin >> S[i][j];
    }
  }
  
  
  int count = 0;
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      if (S[i][j] == '#') cout << '#';
      if (S[i][j] == '.'){
        for (int k=-1; k<2; k++){
          for (int l=-1; l<2; l++){
            if (i+k>=0 && i+k<H && j+l>=0 && j+l<W){
              if(S[i+k][j+l] == '#') count++;
            }
          }
        }
        cout << count;
        count = 0;
      }
    }
    cout << endl;
  }
}