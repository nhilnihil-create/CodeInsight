#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

ll N;

int rec(string S, ll N){
  if (stol(S) > N) return 0;

  bool check_7 = false;
  bool check_5 = false;
  bool check_3 = false;
  rep(i, S.size()){
    if (S[i]=='7') check_7 = true;
    else if (S[i]=='5') check_5 = true;
    else if (S[i]=='3') check_3 = true;
  }

  int res;
  if (check_7 && check_5 && check_3) res = 1;
  else res = 0;

  res += rec(S + "7", N);
  res += rec(S + "5", N);
  res += rec(S + "3", N);

  return res;
}

int main(){
  cin >> N;
  cout << rec("0", N) << endl;
}
