#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  string S; cin >> S;

  string Ans = "NA";

  int BunkatsuA = (S[0]-'0')*10 + (S[1]-'0');
  int BunkatsuB = (S[2]-'0')*10 + (S[3]-'0');

  if ( 1 <= BunkatsuA && BunkatsuA <= 12 ) {
    if ( 1 <= BunkatsuB && BunkatsuB <= 12 ) Ans = "AMBIGUOUS";
    else Ans = "MMYY";
  } else if ( 1 <= BunkatsuB && BunkatsuB <= 12 ) Ans = "YYMM";

  cout << Ans << endl;
}
