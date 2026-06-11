#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int a,b,c,num[5];
  cin >> num[0] >> num[1] >> num[2];

  int cnt = 0;
  while(!(num[0] == num[1] & num[1] == num[2])) {
    sort(num,num+3);
    if(num[0] < num[1]) {
      num[0] += 2; cnt++;
    } 
    else if(num[0] == num[1]) {
      num[0]++; num[1]++; cnt++;
    }
  }  
  cout << cnt << endl;
}
