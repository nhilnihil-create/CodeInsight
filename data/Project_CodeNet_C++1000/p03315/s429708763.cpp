#include <bits/stdc++.h>
using namespace std;

int main() {
   string S;
   cin >> S;
   int count = 0;
   if( S.at(0) == '+' ) count++;
   else count--;
   if( S.at(1) == '+' ) count++;
   else count--;
   if( S.at(2) == '+' ) count++;
   else count--;
   if( S.at(3) == '+' ) count++;
   else count--;
  cout << count << endl;
}