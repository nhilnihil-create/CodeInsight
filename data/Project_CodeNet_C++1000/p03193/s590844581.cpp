#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H, W;
  cin >> N >> H >> W;
  int A[N], B[N];
  int ita =0;
  
  for(int i=0; i<N; i++) {
    cin>> A[i] >> B[i];
    if(A[i] >= H && B[i] >= W) ita++;
  } 
    cout << ita << endl;
}
