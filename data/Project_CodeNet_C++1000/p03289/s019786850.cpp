#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

bool check(string S){
  if (S[0] != 'A') return false;
  int cnt = 0;  //大文字のCがいくつあるか
  for (int i = 2; i < S.size() - 1; i++){
    if (S[i] == 'C') cnt ++;
  }
  if (cnt != 1) return false;
  int upper = 0;  //大文字の個数
  rep(i, S.size()){
    if (S[i] >= 'A' && S[i] <= 'Z') upper ++;
  }
  if (upper != 2) return false;
  return true;
}

int main(void){
  string S;
  cin >> S;

  if (check(S)){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
}
