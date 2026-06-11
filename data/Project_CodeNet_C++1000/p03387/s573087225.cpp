#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  int cnt = 0;
  while(!(a == b & b == c)) {
    if(a <= b & b <= c) {
      if(a == b) {
        a++; b++; cnt++;
      } else {
          a += 2; cnt++;
      }
    } else if(a <= c & c <= b) {
        if(a == c) {
          a++; c++; cnt++;
        } else {
            a += 2; cnt++;
        }
    } else if(b <= a & a <= c) {
        if(b == a) {
          b++; a++; cnt++;
        } else {
            b += 2; cnt++;
        }
    } else if(b <= c & c <= a) {
        if(b == c) {
          b++; c++; cnt++;
        } else {
            b += 2; cnt++;
        }
    } else if(c <= a & a <= b) {
        if(c == a) {
          c++; a++; cnt++;
        } else {
            c += 2; cnt++;
        }
    } else if(c <= b & b <= a) {
        if(c == b) {
          c++; b++; cnt++;
        } else {
            c += 2; cnt++;
        }
    }
  }  
  cout << cnt << endl;
}