#include <bits/stdc++.h>
using namespace std;
bool yakusu(int S) {
  int ans = 1;
  for(int i = 1; i < S; i++) {
    if(S % i == 0) {
      ans++;
    }
  }
  if(ans == 8) return true;
  else return false;
}
int main () {
  int N;
  cin >> N;
  int sasa = 0;
  for(int i = 1; i <= N; i+=2) {
    if(yakusu(i)) sasa++;
  }
  cout << sasa << endl;
}