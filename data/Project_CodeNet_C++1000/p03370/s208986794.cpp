#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  for(int i = 0; i < n; i++) cin >> m[i];
  int min = m[0];  
  for(int i = 0; i < n; i++){
    x -= m[i];
    if(min > m[i]) min = m[i];
  }
  cout << n + x / min << endl;
  return 0;
}