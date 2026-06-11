#include<bits/stdc++.h>
using namespace std;

int main(void){
  char C[2][3];
  int cnt = 0;
  for(int i = 0 ; i < 2; i++){
    for(int j = 0; j < 3; j++){
      cin >> C[i][j];
    }
  }
  if(C[0][0] == C[1][2])
    cnt++;
  if(C[0][1] == C[1][1])
    cnt++;
  if(C[0][2] == C[1][0])
    cnt++;
  if(cnt == 3) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
