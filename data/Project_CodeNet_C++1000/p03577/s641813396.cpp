#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  string s, fest = "FESTIVAL";
  cin >> s;
  cout << s.substr(0, s.length() - fest.length()) << endl;
  return 0;
}