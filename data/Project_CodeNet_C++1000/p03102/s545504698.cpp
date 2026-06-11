#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m,c,A[30][30],B[30];
  cin >> n >> m >> c;

  for(int i = 0; i < m; i++) 
    cin >> B[i];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      cin >> A[i][j];
  }

  int num = 0;
  for(int i = 0; i < n; i++) {
    int sum = 0;
    for(int j = 0; j < m; j++)
      sum += A[i][j]*B[j];
    if(sum + c > 0) num++;
  }

  cout << num << endl; 
}