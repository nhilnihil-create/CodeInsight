#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,x;
  cin >> n >> x;
  vector<int> m(n);
  int d=100000;
  for(int i=0;i<n;i++){
    cin >> m.at(i);
    x-=m.at(i);
    d=min(d,m.at(i));
  }
  cout << n+x/d << endl;
}