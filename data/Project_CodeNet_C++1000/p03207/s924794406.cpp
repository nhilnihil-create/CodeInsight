#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int sum = 0, tmp = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    sum += a; 
    tmp = max(tmp, a);
  }
  sum -= tmp/2;
  cout << sum << endl;
}