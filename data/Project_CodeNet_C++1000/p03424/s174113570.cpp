#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  string S[N];
  rep(i,N) cin >> S[i];

  bool flag = false;
  rep(i,N){
    if (S[i] == "Y") flag = true;
  }
  if (flag) cout << "Four" << endl;
  else cout << "Three" << endl;
}
