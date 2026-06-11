#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int a[2][n];
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }
  
  int o[n] = {0};
  o[0] = a[0][0]; 
  int t[n] = {0};
  t[0] = a[1][0];
  for(int i = 1; i < n; i++){
    o[i] = a[0][i] + o[i-1];
  }
  for(int i = 1; i < n; i++){
    t[i] = a[1][i] + t[i-1];
  }
  
  int cmax = o[0] + t[n-1];
  for(int i = 1; i < n; i++){
    int max = o[i] + t[n-1] - t[i-1];
    if(max > cmax){
      cmax = max;
    }
  }
  
  cout << cmax << endl;
    
}