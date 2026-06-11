#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,a[200];
  cin >> n; 
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  int ma = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      if(ma < abs(a[i]-a[j]))
        ma = abs(a[i]-a[j]);
    }
  }
  cout << ma << endl;
}
