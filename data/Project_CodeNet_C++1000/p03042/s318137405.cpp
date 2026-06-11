#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string S;
  cin >> S;
  bool YYMM = true;
  bool MMYY = true;
  if ((S[2]=='0' && S[3] == '0') || (S[2] == '1' && S[3] >= '3') || (S[2] >= '2'))
  {
    YYMM = false;
  }
  if ((S[0]=='0' && S[1] == '0') || (S[0] == '1' && S[1] >= '3') || (S[0] >= '2'))
  {
    MMYY = false;
  }

  if (YYMM && MMYY)
  {
    cout << "AMBIGUOUS" << endl;
  } else if (YYMM && !MMYY)
  {
    cout << "YYMM" << endl;
  } else if (!YYMM && MMYY)
  {
    cout << "MMYY" << endl;
  } else
  {
    cout << "NA" << endl;
  }
  
  
  
  
  return 0;
}
