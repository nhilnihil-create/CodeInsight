#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int p[n];
  memset(p,0,sizeof(p));
  for(int i = 0; i < n; ++i){
    cin >> p[i];
  }
  
  sort(p,p+n);
  
  int res = 0;
  for(int i = 0; i < n-1; ++i){
    res += p[i];
  }
  res += p[n-1]/2;
  
  cout << res << endl;
}