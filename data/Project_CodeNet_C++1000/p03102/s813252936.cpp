#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, C;
  int temp;
  vector<int> B(M); 
  cin >> N >> M >> C;
  for (int i=0;i<M;i++){
    cin >> temp;
    B[i] = temp;
  }
  int count = 0;
  for (int i=0;i<N;i++){
    int sum = 0;
    for (int j=0;j<M;j++){
      cin >> temp;
      sum += temp*B[j];
    }
    if (sum + C > 0) count++; 
  }
  cout << count << endl;
}