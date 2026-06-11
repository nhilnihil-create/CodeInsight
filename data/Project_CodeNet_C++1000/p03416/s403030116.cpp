#include<bits/stdc++.h>
using namespace std;

bool p(int n){
  return ((n/10000) == (n%10) && (n/1000 - (n/10000*10)) == ((n%100-n%10)/10));
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