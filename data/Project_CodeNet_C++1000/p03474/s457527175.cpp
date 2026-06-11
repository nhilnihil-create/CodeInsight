#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int A, B;
  string S;
  cin >> A >> B >> S;

  if (S[A] != '-'){
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < A; i++){
    if (S[i] == '-'){
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = A + 1; i < A + B + 1; i++){
    if (S[i] == '-'){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
