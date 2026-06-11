#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll N;
  string march="MARCH";
  cin >> N;
  map<char,ll> M;
  string S;
  for (ll i=0; i<N; i++) {
    cin >> S;
    for (char s:march) {
      if (s==S[0]) {
        goto OUT;
      }
    }
    continue;
  OUT:
    M[S[0]]++;
  }
  
  ll sum=0;
  for (int i=0; i<5; i++) {
    for (int j=i+1; j<5; j++) {
      for (int k=j+1; k<5; k++) {
        sum+=M[march[i]]*M[march[j]]*M[march[k]];
      }
    }
  }
  cout << sum << endl;
}
 