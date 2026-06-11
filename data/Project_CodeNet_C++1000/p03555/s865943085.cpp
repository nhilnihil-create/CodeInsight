#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  string S1, S2; cin >> S1 >> S2;
  bool flag = true;
  if (S1[0] != S2[2]) flag = false;
  if (S1[1] != S2[1]) flag = false;
  if (S1[2] != S2[0]) flag = false;
  
  if (flag) cout << "YES" << endl;
  else cout << "NO" << endl;

}