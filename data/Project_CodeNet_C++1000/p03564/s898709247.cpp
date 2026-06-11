#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N>>K;
  int c=1;//初期値

  for (int i = 0; i < N; i++) {
    if(c<K){//c=２倍する際の増加値
      c+=c;
  }
  else if(c>=K){
    c+=K;
  }
  }
    cout << c << endl;
}