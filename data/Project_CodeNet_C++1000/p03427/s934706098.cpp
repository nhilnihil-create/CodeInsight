#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  long long N; cin >> N;
  
  int ans = 0;
  int size = 0;
  vector<int> m(0);
  
  if(N<10) {
    cout << N << endl;
    return 0;
  }
  
  while(N > 0) {
    size++;
    m.push_back(N%10);
    N /= 10;
  }
  
  int n=1;
  rep(i, size-1) {
    if(m[i] != 9) n=0;
  }

  if(n==1) {
    cout << 9*(size-1)+m[size-1] << endl;
    return 0;
  }
  
  cout << 9*(size-1) + m[size-1]-1 << endl;
  
}
