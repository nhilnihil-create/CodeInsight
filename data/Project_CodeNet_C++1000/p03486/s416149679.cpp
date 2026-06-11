#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s,t;
  cin >> s >> t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  reverse(t.begin(),t.end());
  if(s < t) cout << "Yes" << endl;
  else cout << "No" << endl;
}