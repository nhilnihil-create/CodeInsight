#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n, a[11];
int main(){
  cin >> n;
  rep(i, n) cin >> a[i];
  
  int sum = 1;
  rep(i, n){
    if(a[i] % 2 == 0){
      sum *= 2;
    }
  }
  cout << pow(3, n) - sum << endl;
    
  return 0;
}
