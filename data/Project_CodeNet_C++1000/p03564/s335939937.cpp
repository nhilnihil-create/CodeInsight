#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,count=0,ans=1; cin >> N >> K;
  for(int i=0; i<N; i++){
    if(ans*2 < ans+K) ans *=2;
    else ans +=K;
  }
  cout << ans << endl;
}