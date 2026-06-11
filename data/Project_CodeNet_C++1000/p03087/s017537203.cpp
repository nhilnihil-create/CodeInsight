#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, Q, r, l, cnt = 0;
  string S;
  cin >> N >> Q >> S;
  
  vector<ll> flag(S.size(), 0);
  for(ll i = 0; i < S.size(); i++) {
    if(i > 0) {
      if((S.at(i) == 'C') && (S.at(i - 1) == 'A')) cnt++;
      flag.at(i) = cnt;
    }
  }

  for(ll i = 0; i < Q; i++) {
    cin >> r >> l;
    cout << flag.at(l - 1) - flag.at(r - 1) << endl;
  }
}