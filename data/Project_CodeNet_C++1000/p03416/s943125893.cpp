#include<bits/stdc++.h>
using namespace std;

bool p(int a){
  return (a % 10 == a / 10000 && (a % 100 - a % 10) / 10 == (a / 1000 - a / 10000 * 10));
}

int main(){
  int a,b;
  cin >> a >> b;
  int ans = 0;
  for(int i = a; i < b + 1; i++){
    if(p(i)) ans++;
  }
  cout << ans << endl;
}