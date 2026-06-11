#include <iostream>
#include <algorithm>

using namespace std;

int r[10];

int ntoi(int i, int c[10][10]) {
  int min_d = 1000, n = 0;
  
  for (int j = 0; j < 10; j++){
    if (min_d < c[j][i] && i != j){
      n = j;
      min_d = c[j][i];
    }
  }

  return n;
}

int main(){
  int H, W;
  int c[10][10];
  cin >> H >> W;
  int A[H][W];

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      cin >> c[i][j];
    }
  }

  for (int k = 0; k < 10; k++){
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        if (c[i][j] > c[i][k] + c[k][j]) c[i][j] = c[i][k] + c[k][j];
      }
    }
  }

  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cin >> A[i][j];
    }
  }

  int mp = 0;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if(A[i][j] != -1) mp += c[A[i][j]][1];
    }
  }

  printf("%d\n", mp);

}
