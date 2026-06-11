#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  int N;
  cin >> N;
  set<string> setM, setA, setR, setC, setH;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    if (S[0] == 'M') {
      setM.insert(S);
    } else if (S[0] == 'A'){
      setA.insert(S);
    } else if (S[0] == 'R') {
      setR.insert(S);
    } else if (S[0] == 'C') {
      setC.insert(S);
    } else if (S[0] == 'H') {
      setH.insert(S);
    }
  }
  
  vector<ll> num(5,0);
  num[0] = setM.size();
  num[1] = setA.size();
  num[2] = setR.size();
  num[3] = setC.size();
  num[4] = setH.size();

  
  ll ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      for (int k = j+1; k < 5; k++) {
        ans += num[i] * num[j] * num[k];
      }
    }
  }
  cout << ans << endl;
}