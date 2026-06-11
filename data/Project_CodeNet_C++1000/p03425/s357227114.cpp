#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;
 
int main() {
  ll N, cnt = 0;
  string S;
  cin >> N;
  vector<ll> initial(5, 0);
  for(ll i = 0; i < N; i++) {
    cin >> S;
    if(S.at(0) == 'M') initial.at(0)++;
    else if(S.at(0) == 'A') initial.at(1)++;
    else if(S.at(0) == 'R') initial.at(2)++;
    else if(S.at(0) == 'C') initial.at(3)++;
    else if(S.at(0) == 'H') initial.at(4)++;
  }
  for(ll i = 0; i < 3; i++) {
    for(ll j = i + 1; j < 4; j++) {
      for(ll k = j + 1; k < 5; k++) {
        cnt+= initial.at(i) * initial.at(j) * initial.at(k);
      }
    }
  }
  cout << cnt << endl;
}