#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  int N;
  cin >> N;
  bool x = false;
  for(int i = 0; 4*i<=N; i++){
    for(int j = 0; 7*j<=N; j++){
      if(4*i+7*j==N){
        x = true;
      }
    }
  }
  if(x) cout << "Yes" << endl;
  else cout << "No" << endl;
}      