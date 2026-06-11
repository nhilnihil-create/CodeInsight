#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;cin>>s;
  if (s.size()==2)cout<<s;
  else {
    reverse(s.begin(), s.end());
    cout<<s;
  }
}
