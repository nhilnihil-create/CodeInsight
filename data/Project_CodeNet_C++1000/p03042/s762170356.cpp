#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

bool yymm(string s) {
  int v = (s.at(2) - '0') * 10 + (s.at(3) - '0');
  if (v > 12 || v == 0) return false;
  return true;
}
bool mmyy(string s) {
  int v = (s.at(0) - '0') * 10 + (s.at(1) - '0');
  if (v > 12 || v == 0) return false;
  return true;
}

int main()
{
  string s;
  cin >> s;

  if (yymm(s) && mmyy(s)) {
    cout << "AMBIGUOUS" << endl;
  } else if (yymm(s)) {
    cout << "YYMM" << endl;
  } else if (mmyy(s)) {
    cout << "MMYY" << endl;
  } else {
    cout << "NA" << endl;
  }
  
  return 0;
}