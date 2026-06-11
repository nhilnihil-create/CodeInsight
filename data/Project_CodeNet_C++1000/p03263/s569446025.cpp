#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;cin >> H >> W;
  vector<vector<int>> A(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> A[i][j];
    }
  }
  int N = 0;
  vector<vector<int>> OP(H*W,vector<int>(4));
  for(int i=0;i<H;i++){
    for(int j=0;j<W-1;j++){
      if(A[i][j]%2>0){
        OP[N][0]=i;
        OP[N][1]=j;
        OP[N][2]=i;
        OP[N][3]=j+1;
        N ++;
        A[i][j] --;
        A[i][j+1] ++;
      }
    }
    if(i<H-1&&A[i][W-1]%2>0){
      OP[N][0]=i;
      OP[N][1]=W-1;
      OP[N][2]=i+1;
      OP[N][3]=W-1;
      N ++;
      A[i][W-1] --;
      A[i+1][W-1] ++;
    }
  }
  cout << N << endl;
  for(int i=0;i<N;i++){
    cout << OP[i][0]+1 << " " << OP[i][1]+1 << " " << OP[i][2]+1 << " " << OP[i][3]+1 << endl;
  }
}