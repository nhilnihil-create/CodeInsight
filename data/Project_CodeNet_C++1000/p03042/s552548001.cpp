#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string S;
  cin >> S;

  int L = (S[0] - '0') * 10 + (S[1] - '0');
  int R = (S[2] - '0') * 10 + (S[3] - '0');

  if (L >= 1 && L <= 12){
    if (R >= 1 && R <= 12) cout << "AMBIGUOUS" << endl;
    else cout << "MMYY" << endl;
  }else{
    if (R >= 1 && R <= 12) cout << "YYMM" << endl;
    else cout << "NA" << endl;
  }
}
