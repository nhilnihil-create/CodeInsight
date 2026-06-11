#include<iostream>
#include<map>
using namespace std;

int C[10][10], A[50000];

int main() {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) cin >> C[i][j];
  for (int i = 0; i < H*W; i++) cin >> A[i];
  for (int k = 0; k < 10; k++)
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
        C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
  int sum = 0;
  for (int i = 0; i < H*W; i++) {
    if (A[i] != -1) sum += C[A[i]][1];
  }
  cout << sum << endl;
}