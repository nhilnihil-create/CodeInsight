#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

string rotate(string S){
  return S.substr(1) + S[0];
}

int main(void){
  string S, T;
  cin >> S >> T;

  int N = S.size();

  rep(i,N){
    if (S == T){
      cout << "Yes" << endl;
      return 0;
    }
    S = rotate(S);
  }
  cout << "No" << endl;
  return 0;
}
