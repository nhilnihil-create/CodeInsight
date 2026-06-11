#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int tmp = 0, sum = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a > tmp){
      sum += tmp;
      tmp = a;
    }
    else sum += a;
  }
  if(sum > tmp) cout << "Yes" << endl;
  else cout << "No" << endl;
}