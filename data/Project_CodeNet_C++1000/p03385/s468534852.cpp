#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main(){
  string S;
  cin >> S;
  int flag = 0;
  REP(i,3) {
    flag |= 1 << (S[i] - 'a');
  }
  if ( flag == 7 ) cout << "Yes" << endl;
  else cout << "No" << endl;
}
      