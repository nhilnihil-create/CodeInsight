#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N,moto=1,hiku=1;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    moto *= 3;
    if(vec[i]%2 == 0){
      hiku *= 2;
    }
  }
  cout << moto-hiku << endl;
}
