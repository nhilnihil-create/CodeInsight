#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll N; cin >> N;
  vector<vector<char> > a(N, vector<char>(N, '0'));
  vector<vector<char> > b(N, vector<char>(N, '0'));
  
  ll ans = 0;
  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < N; j++){
      cin >> a[i][j];
    }
  }
  
  for(ll n = 0; n < N; n++){
    for(ll i = 0; i < N; i++){
      for(ll j = 0; j < N; j++){
        b[i][j] = a[i][(j + n)%N];
      }
    }
    bool clr = true;
    for(ll i = 0; i < N; i++){
      for(ll j = 0; j < N; j++){
        if(b[i][j] != b[j][i]) {
          clr = false;
          break;
        }
      }
    }
    if(clr) ans += N;
  }
  
  cout << ans << endl;
}