#include <bits/stdc++.h>
using namespace std;

int main() {
int k;
  cin >> k;
 if(k%2 != 0){
   int t = (k-1)/2;
   int d = (k+1)/2;
   cout << d*t << endl;
 }
  else cout << (k/2)*(k/2) << endl;
}