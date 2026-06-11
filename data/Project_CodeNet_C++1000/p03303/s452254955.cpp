#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  string S;
  cin >> S;
  int N;
  cin >> N;
  for( int i = 0; i < S.size(); i += N ){
    cout << S.at(i);
  }
  cout << endl;
}
