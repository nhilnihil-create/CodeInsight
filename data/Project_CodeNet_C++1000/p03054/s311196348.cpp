#include <iostream>
using namespace std;
int h, w, n, sr, sc;
string s, t;

int main() {
  cin >> h >> w >> n >> sr >> sc >> s >> t;

  int L = 1, R = w, U = 1, D = h;
  for(int i = n-1; i >= 0; --i) {
    if(t[i] == 'R') {
      if(1 < L && L < w) --L;
    }
    if(t[i] == 'L') {
      if(1 < R && R < w) ++R;
    }

    if(s[i] == 'R') --R;
    if(s[i] == 'L') ++L;
  }
  if(L > sc || sc > R) { cout << "NO"; return 0; }

  for(int i = n-1; i >= 0; --i) {
    if(t[i] == 'D') {
      if(1 < U && U < h) --U;
    }
    if(t[i] == 'U') {
      if(1 < D && D < h) ++D;
    }

    if(s[i] == 'D') --D;
    if(s[i] == 'U') ++U;
  }
  if(U > sr || sr > D) { cout << "NO"; return 0; }

  cout << "YES";
  return 0;
}