#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >>n;
  double x[n];
  string u[n];
  rep(i,n) cin >>x[i] >>u[i];
  double sum = 0;
  rep(i,n){
    if(u[i] == "BTC") sum += x[i]*380000;
    else sum += x[i];
  }
  cout << fixed << setprecision(9) << sum << endl;
  return 0;
}