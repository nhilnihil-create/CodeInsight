#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> y(3,0); cin>>y[0]>>y[1]>>y[2];
  sort(y.begin(),y.end());
  cout << y[0]*y[1]/2 << endl;
}