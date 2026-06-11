#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,v[30],c[30],ans[30];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> v[i];
  for(int i = 0; i < n; i++)
    cin >> c[i];
  
  int sum = 0;
  for(int i = 0; i < n; i++) {
    ans[i] = v[i] - c[i];
    if(ans[i] > 0) sum += ans[i];
  }
  cout << sum << endl; 
}