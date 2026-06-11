#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int stringCount(string s, char c) {
  return count(s.cbegin(), s.cend(), c);
}
int main(void){

  string str;
  cin >> str;
  cout << stringCount(str,'1') << endl;
}
