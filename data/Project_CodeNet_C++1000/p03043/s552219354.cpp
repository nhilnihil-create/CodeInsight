#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,k; cin >>n >>k;
  double prototal = 0;
  for(int i = 1; i<=n; i++){
    double pro = 1.0/n;
    int sum = i;
    while(sum<k){
      pro /= 2;
      sum *= 2;
    }
    prototal += pro;
  }
  cout << fixed << setprecision(12) << prototal << endl;
  return 0;
}