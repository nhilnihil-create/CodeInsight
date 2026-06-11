#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0, M = 0;
  cin >> N >> M;
  string S;
  cin >> S;
  rep(i,N){
    if(S[i] == '-'){
      cout << "No";
      return 0;
    }
  }
  if(S[N] != '-'){
    cout << "No";
      return 0;
  }
  rep(i,M){
    if(S[i + N + 1] == '-'){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}