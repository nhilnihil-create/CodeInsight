#include <bits/stdc++.h>

 using namespace std;

 int main() {
   string S;
   cin >> S;

   if (S.length() == 2) cout << S << endl;
   if (S.length() == 3) cout << S.at(2) << S.at(1) << S.at(0) << endl;
 }
