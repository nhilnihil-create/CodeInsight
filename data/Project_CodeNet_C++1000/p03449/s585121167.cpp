#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  vector<int> a(n),b(n);
  
  for ( int i = 0; i < n; i++)cin >> a[i];  
  for ( int i = 0; i < n; i++)cin >> b[i];
  
  int saidai = 0,goukei,flag = 0;
  
  while(flag < n){
    goukei = 0;
    for ( int i = 0; i <= flag; i++)goukei += a[i];
    for ( int i = flag; i < n; i++) goukei+= b[i];
    saidai = max(saidai,goukei);
    flag++;
  }
  
  cout << saidai << endl; 
  
}