#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {

  int X; cin >> X;
  int ans = 1;
  for(int i = 1; i * i <= X; i++){
    for(int k = 2; k <= X; k++){
      if(pow(i,k) <= X) ans = max(ans, (int)pow(i, k));
    }
  }

  cout << ans << endl;

}
