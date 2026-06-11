#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t lenS,lenT;
  string S,T;
  cin >> lenS >> lenT >> S >> T;

  int64_t cand= lcm(lenS, lenT);
  int64_t Nmatch= gcd(lenS, lenT);
  int64_t fracS= lenS/ Nmatch;
  int64_t fracT= lenT/ Nmatch;

  bool satisfied= true;
  for(int64_t i=0; i<Nmatch; i++){
    satisfied= satisfied && (S.at(i* fracS)==T.at(i* fracT));
  }

  int64_t ans= satisfied ? cand
                         : -1;
  cout << ans << endl;
}