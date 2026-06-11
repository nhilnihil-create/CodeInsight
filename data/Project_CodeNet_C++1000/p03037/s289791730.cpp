#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int sho = -1000000, dai = 1000000, tmpsho, tmpdai;
  for (int i = 0; i < M; i++){
    cin >> tmpsho >> tmpdai;
    sho = max(sho, tmpsho);
    dai = min(dai, tmpdai);
  }
  int c = 0;
  for (int i = 1; i <= N; i++){
    if(sho <= i && i <= dai) c++;
  }
  cout << c << endl;
  return 0;
}