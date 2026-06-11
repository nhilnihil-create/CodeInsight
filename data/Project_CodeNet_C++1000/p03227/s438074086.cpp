#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  string s;
  cin >> s;
  if (s.length() == 3) {
    reverse(s.begin(), s.end());
  }
  cout << s << endl;
  return 0;
}