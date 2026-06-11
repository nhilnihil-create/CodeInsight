#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> an(n), bn(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  for(int i=0; i<n; ++i) cin >> bn[i];
  ll aplus2 = 0, bplus1 = 0;
  for(int i=0; i<n; ++i){
    if(an[i] > bn[i]) bplus1 += an[i] -bn[i];
    if(an[i] < bn[i]) aplus2 += (bn[i] -an[i]) /2;
  }
  if(bplus1 > aplus2) cout << "No" << endl;
  else cout << "Yes" << endl;
}