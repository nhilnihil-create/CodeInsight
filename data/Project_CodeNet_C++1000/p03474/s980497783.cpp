#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main() {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;
  bool flag = true;
 for(int i = 0; i < A; i++) {
   if(S[i] >= '0' && S[i] <= '9') continue;
   else { flag = false; }
 }
 if(S[A] != '-') {
   flag = false;
 }

 for(int i = A + 1; i < A + B + 1; i++) {
   if(S[i] >= '0' && S[i] <= '9') continue;
   else { flag = false; }
 }
 if(flag)
 cout << "Yes";
 else
 {
   cout << "No";
 }
  


  return 0;
}