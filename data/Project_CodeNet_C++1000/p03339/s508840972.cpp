#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, cnt, min = 0;
  string S;
  cin >> N >> S;
  for(ll i  = 1; i < N; i++) {
    if(S.at(i) == 'E') min++;
  }
  cnt = min;
  for(ll i  = 1; i < N; i++) {
    if((S.at(i - 1) == 'E') && (S.at(i) == 'E')) {
      cnt--;
      if(cnt <= min) min = cnt;
    }
    else if((S.at(i - 1) == 'W') && (S.at(i) == 'W')) cnt++;
  }
  cout << min << endl;
}