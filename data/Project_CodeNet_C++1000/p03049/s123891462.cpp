#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

int main() {
  int N;
  cin >> N;
  int cnt=0, cnta=0, cntb=0, cntn=0;
  for(int i = 0; i < N; i++) {
    string S;
    cin >> S;
    for(int j = 0; j < S.size()-1; j++) {
      if(S.at(j) == 'A'&&S.at(j+1) == 'B') cnt++;
    }
    if(S.at(0) == 'B') cntb++;
    if(S.at(S.size()-1) == 'A') cnta++;
    if(S.at(0) == 'B'&&S.at(S.size()-1) == 'A') cntn++;
  }
  int a = 0;
  if(cntn == cnta && cnta!=0 && cntn == cntb) a=1;
  cout << cnt + min(cnta, cntb) - a << endl;
}
        