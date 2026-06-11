#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,ans=1; cin >> N >> K;
  for(int i=1; i <= N; i++){
    ans = min(ans*2,ans+K);
  }
  cout << ans << endl;
}
