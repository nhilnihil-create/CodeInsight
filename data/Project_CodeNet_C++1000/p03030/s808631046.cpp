#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

struct Rest {
  string name;
  int value;
  int label;
};

int main() {
  int n;
  Rest R[110];
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> R[i].name >> R[i].value;
  for(int i = 0; i < n; i++)
    R[i].label = i+1;
  
  for(int i = 0; i < n; i++) {
    for(int j = n-1; j >= i+1; j--) {
      if(R[j].name < R[j-1].name) 
        swap(R[j],R[j-1]);
      else if(R[j].name == R[j-1].name) {
        if(R[j].value > R[j-1].value)
          swap(R[j],R[j-1]);
      }
    }
  }
  
  for(int i = 0; i < n; i++) 
    cout << R[i].label << endl;
}