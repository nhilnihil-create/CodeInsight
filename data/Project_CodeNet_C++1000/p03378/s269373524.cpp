#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,x; cin >> n >> m >> x;
  set<int> a;
  for(int i = 0; i < m; i++){
    int b; cin >> b;
    a.insert(b);
  }
  int cnt = 0;
  if(x < n/2){
    for(int i = 0; i <= x; i++){
      if(a.count(i)) cnt++;
    }
  }
  else{
    for(int i = x; i <= n; i++){
      if(a.count(i)) cnt++;
    }
  }
  
  cout << cnt;
}