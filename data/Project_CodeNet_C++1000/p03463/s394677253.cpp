#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  
  if((b-a) % 2 == 0)
    cout << "Alice" << endl;
  else
    cout << "Borys" << endl; 
}