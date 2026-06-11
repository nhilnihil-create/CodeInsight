#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  int x[100],y[100],ma = 0;
  for(int i = 1; i < n; i++) {
    string a = s.substr(0,i);
    string b = s.substr(i, n-i);
    for(int i = 0; i < 100; i++) {
      x[i] = 0; y[i] = 0;
    }
    for(char ch = 'a'; ch <= 'z'; ch++) {
      for(int j = 0; j < i; j++)
        if(ch == a[j]) x[ch-'a']++;
      for(int j = 0; j < n-i; j++)
        if(ch == b[j]) y[ch-'a']++;
    }
    int sum = 0;
    for(int i = 0; i < 26; i++)
      if(x[i] > 0 & y[i] > 0) sum++;
    ma = max(ma, sum);
  }
  cout << ma << endl;
}