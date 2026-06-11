#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll A, B;
  cin >> A >> B;
  
  ll count = 0;
  while (A <= B) {
    count++;
    A *= 2;
  }
  
  cout << count << endl;
  
  
}