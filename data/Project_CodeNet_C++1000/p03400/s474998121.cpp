#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D,X;
  int sum = 0;
  
  cin >> N >> D >> X;
  for(int i=0;i<N;++i){
    int s; cin >> s;
    int j=0;
    while(j*s + 1 <= D){
      sum += 1;
      j++;
    }
  }
  cout << sum + X << endl;
  return 0;
}
