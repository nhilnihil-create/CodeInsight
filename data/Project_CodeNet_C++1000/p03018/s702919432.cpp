#include <iostream>

using namespace std;

int main() {
  string in;
  cin >> in;
  long res = 0;
  for (long i = 0; i < in.size(); i++) {
    if (in[i] == 'B' || in[i] == 'C') continue;
    long acnt = 0;
    while (in[i] == 'A') {
      acnt++;
      i++;
    }
    long bccnt = 0;
    while (in[i] == 'B' && in[i+1] == 'C') {
      bccnt++;
      i=i+2;
    }
    i--;
    res += acnt*bccnt;
    if (bccnt > 0) {
      for (long j = 0; j < acnt; j++) {
        if (i < in.size()-1) {
          in[i] = 'A';
          i--;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}