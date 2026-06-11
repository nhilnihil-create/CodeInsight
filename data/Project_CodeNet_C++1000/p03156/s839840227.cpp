#include <bits/stdc++.h>
using namespace std;
int p(vector<int>x,int y,int z){
  int l=0;
  for(int i=0;i<x.size();i++){
    if(y<x.at(i) && x.at(i)<=z){
    l++;
    } 
  }
  return l;
}
int main() {
  int n,a,b;
  cin >> n >> a >> b;
  vector<int>c(n);
  for(int i=0;i<n;i++){
  cin >> c.at(i);
  }
  cout << min(min(p(c,0,a),p(c,a,b)),p(c,b,21)) << endl;
}
