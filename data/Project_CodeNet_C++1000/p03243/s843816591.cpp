#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
vector<int> input(int N) {
  vector<int> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec.at(i);
  }
  return vec;
}

int main() {
  int n;
  cin >> n;
  for(int i=n;i<1000;i++){
    if(i/100==(i%100)/10&&i/100==i%10){
      cout << i << endl;
      break;
    }
  }
}
