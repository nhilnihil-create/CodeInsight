#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> b(n);
  for(int i = 0; i < n; i++) cin >> b.at(i);
  
  vector<int> a(n);
  int now;
  for(int i = 0; i < n; i++){
    now = -1;
    for(int j = 0; j < n-i; j++){
      if(j+1 == b.at(j)) now = j+1;
    }
    a.at(i) = now;
    if(now == -1) break;
    b.erase(b.begin()+now-1);
  }
  
  if(now == -1) cout << now << endl;
  else{
    for(int i = n-1; i >= 0; i--){
      cout << a.at(i) << endl;
    }
  }
}