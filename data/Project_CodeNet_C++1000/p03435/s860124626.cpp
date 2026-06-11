#include <bits/stdc++.h>
using namespace std;

#define N 3

int main() {
  int C[N][N];
  for(int i=0 ; i<N ; i++)
    for(int j=0 ; j<N ; j++)
      cin >> C[i][j];
  
  for(int i=0 ; i<N ; i++){
    int x=C[i][0]-C[(i+1)%N][0];
    if(C[i][1]-C[(i+1)%N][1]!=x || C[i][2]-C[(i+1)%N][2]!=x){
      cout << "No" << endl;
      return 0;
    }
  }
  
  for(int i=0 ; i<N ; i++){
    int x=C[0][i]-C[0][(i+1)%N];
    if(C[1][i]-C[1][(i+1)%N]!=x || C[2][i]-C[2][(i+1)%N]!=x){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}