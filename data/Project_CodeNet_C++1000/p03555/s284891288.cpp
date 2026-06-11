#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;

int main() {
  string s,t;
  cin >> s >> t;
  if(s[0]==t[2]&&s[1]==t[1]&&s[2]==t[0]){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}