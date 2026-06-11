#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k; cin >> n >>k;
  vector<double>prob(n + 1);
  double a = 1;
  double ans = 0;
  for(int i = 1; i <= n; i++){
    int tmp = i;
    while(tmp < k){
      tmp *=2;
      a /=2.0;
    }
    prob.at(i) = a;
    a = 1;
  }
  
  for(int i = 1; i <= n; i++){
    //cout << prob.at(i) << endl;
    ans += prob.at(i);
  }
  ans /=n;
  printf("%.12f\n",ans);
}
