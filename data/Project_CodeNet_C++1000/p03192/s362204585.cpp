#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int stringcount(string s, char c) {
  return count(s.cbegin(), s.cend(), c);
}

int main() {
  string n;
  cin >> n;
  cout << stringcount(n, '2') << endl;
  return 0;
}