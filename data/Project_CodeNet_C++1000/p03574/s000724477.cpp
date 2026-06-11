#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> S(H+2, vector<char>(W+2));
  for (int i=0; i<H ; i++){
    for (int j=0; j<W ; j++){
      cin >> S[i+1][j+1];
    }
  }
  for (int i=0; i<H ; i++){
    int i2=i+1;
    for (int j=0; j<W ; j++){
      int j2=j+1;
      int B=0;
      if (S[i2][j2]=='.'){
        if(S[i2-1][j2-1]=='#') B++;
        if(S[i2-1][j2]  =='#') B++;
        if(S[i2-1][j2+1]=='#') B++;
        if(S[i2]  [j2-1]=='#') B++;
        if(S[i2]  [j2+1]=='#') B++;
        if(S[i2+1][j2-1]=='#') B++;
        if(S[i2+1][j2]  =='#') B++;
        if(S[i2+1][j2+1]=='#') B++;
        cout << B;
      }else{
        cout << S[i2][j2];
      }
    }
    cout << endl;
  }
 
  return 0;
}
