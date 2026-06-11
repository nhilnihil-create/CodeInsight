#include<bits/stdc++.h>
using namespace std;

bool p(int i){
  return (i / 10000 == i % 10 && (i / 1000 - i / 10000 * 10) == i % 100 / 10);
}

int main(){
  int a,b;
  cin >> a >> b;
  int ans = 0;
  for(int i = a; i <= b; i++){
    if(p(i)) ans++;
  }
  cout << ans << endl;
}