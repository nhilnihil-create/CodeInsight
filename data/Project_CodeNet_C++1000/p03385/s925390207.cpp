#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;

int main() {
  bool Ans=-1;
  //int A; cin >>A;
  //int B; cin >>B;
  string S; cin >> S;
  //cout << Ans << '\n';
  sort(S.begin(),S.end());
  Ans = (S == "abc")? true : false ;
  cout << (Ans==true ? "Yes" : "No" ) << "\n";
  return 0;
}
