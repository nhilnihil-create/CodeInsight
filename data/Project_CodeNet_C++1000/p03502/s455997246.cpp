#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  string n;
  cin >> n;

  int sum = 0;
  for(int i = 0; i < n.size(); i++)
    sum += (n[i]-'0');

  if(stoi(n)%sum == 0)
    cout << "Yes" << endl;
  else cout << "No" << endl;
}