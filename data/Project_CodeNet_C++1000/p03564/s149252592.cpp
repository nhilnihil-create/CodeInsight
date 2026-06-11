#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K, s=1;
  cin >> N >> K;
  for(int i=0;i<N;i++){
    if(s>K) s+=K; else s*=2;
  }
  cout << s << endl; 
}