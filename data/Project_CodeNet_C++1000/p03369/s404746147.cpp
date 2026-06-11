#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  string S;
  cin >> S;
  
  int ans = 700;
  rep(i,3) {
    if (S[i] == 'o') ans += 100;
  }
  
  cout << ans << endl;

}