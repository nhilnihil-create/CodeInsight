#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  int ans = 0;

  cin >> N >> M;
  for(int i=N;i<=M;++i){
      if(i / 10000 == i % 10 && i / 1000 % 10 == i % 100 / 10) ans++;
  }
  cout << ans << endl;
  return 0;
}
