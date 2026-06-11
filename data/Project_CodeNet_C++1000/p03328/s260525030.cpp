#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b;
  cin >> a >> b;

  int sum = 0;
  for(int i = 1; i < b-a; i++)
    sum += i;

  cout << sum-a << endl;
}