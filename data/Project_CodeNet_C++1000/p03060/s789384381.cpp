#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,i,b=0;
  cin >> n;
  vector<int> v(n),c(n);
  for(i=0;i<n;i++){
    cin >> v.at(i);
  }
  for(i=0;i<n;i++){
    cin >> c.at(i);
  }
  for(i=0;i<n;i++){
    b += max(v.at(i)-c.at(i),0);
  }
  cout << b << endl;
}