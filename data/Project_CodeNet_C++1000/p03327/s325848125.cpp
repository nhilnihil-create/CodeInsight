#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  cout << setfill('0');
  
  if(1<=n & n<=999)
    cout << "ABC" << endl;
  else
    cout << "ABD" << endl;
}