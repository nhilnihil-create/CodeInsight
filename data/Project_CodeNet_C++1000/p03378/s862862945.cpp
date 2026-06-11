#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,X;
  int s=0,l=0;
  
  cin >> N >> M >> X;

  for(int i=0;i<M;++i){
    int t; cin >> t;
    if(t < X){
      s += 1;
    }else{
      l += 1;
    }
  }

  cout << min(s,l) << endl;
  return 0;
}
