#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int makenum(char a, char b, char c) {
  int x, y, z;
  x = a - '0';
  y = b - '0';
  z = c - '0';
  return x * 100 + y * 10 + z;
}


int main(){
  string S;
  cin >> S;
  int N = S.size();
  
  int x = abs(makenum(S[0], S[1], S[2]) - 753);
  
  rep1(i,N-3) {
    x = min(x, abs(makenum(S[i], S[i+1], S[i+2]) - 753));
  }
  
  cout << x << endl;

}
