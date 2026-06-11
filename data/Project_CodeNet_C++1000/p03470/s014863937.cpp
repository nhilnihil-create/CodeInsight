#include<bits/stdc++.h>
using namespace std;

bool p(int i){
  return (i / 10000 == i % 10 && (i / 1000 - i / 10000 * 10) == i % 100 / 10);
}

int main(){
  int n;
  cin >> n;
  vector<int> k(n);
  int ans = 0;
  for(int i = 0; i < n; i++){
    cin >> k[i];
  }
  sort(k.begin(),k.end());
  for(int i = 0; i < n-1; i++){
    if(k[i] != k[i+1]) ans++;
  }
  cout << ans+1 << endl;
}