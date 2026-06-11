#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S = "";
  cin >> S;

  for (int i = 0; i < S.size(); i++){
    if (S.at(i) == '/') S.at(i) = '-';
  }
  cout << (S > "2019-04-30" ? "TBD" : "Heisei") << endl;
}