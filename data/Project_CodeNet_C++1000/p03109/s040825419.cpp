#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

string S;

int main(){
  cin >> S;
  int y = stoi(S.substr(0, 4));
  int m = stoi(S.substr(5, 2));
  int d = stoi(S.substr(8, 2));
  if (y <= 2019 && m <= 4 && d <= 30) cout << "Heisei" << endl;
  else cout << "TBD" << endl;
}
