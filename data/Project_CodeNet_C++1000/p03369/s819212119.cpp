#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int P=700;
  if (S[0]=='o') P=P+100;
  if (S[1]=='o') P=P+100;
  if (S[2]=='o') P=P+100;
  cout << P << endl;
}