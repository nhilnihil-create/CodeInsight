#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  string s1,s2;
  cin >> s1 >> s2;
  if(s1[0]==s2[2]&&s2[1]==s1[1]&&s1[2]==s2[0])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}