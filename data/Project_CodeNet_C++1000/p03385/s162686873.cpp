#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  string s;
  cin >> s;
  if(s=="abc"||s=="bac"||s=="acb"||s=="bca"||s=="cab"||s=="cba")
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}