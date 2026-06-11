#include<bits/stdc++.h>
using namespace std;

int h(int a){
  int ans = 0;
  while(a > 0){
    ans += a % 10;
    a /= 10;
    if(!a > 0) return ans;
  }
}

int main(){
  int n;
  cin >> n;
  if(n % h(n) == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}