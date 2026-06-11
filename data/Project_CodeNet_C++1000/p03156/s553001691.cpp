#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  int a,b;cin >> a >> b;
  int x=0,y=0;
  for(int i = 0; i < n; ++i){
    int p; cin >> p;
    x += p > a;
    y += p > b;
  }
  cout << min({n-x,x-y,y}) << endl;
}