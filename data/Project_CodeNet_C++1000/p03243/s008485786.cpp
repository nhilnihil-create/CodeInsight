#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll n; cin >> n;
  for(ll i = n; i < 1000; i++){
    string S = to_string(i);
    if(S[0] == S[1] && S[1] == S[2]){
      cout << S;
      return 0;
    }
  }
}