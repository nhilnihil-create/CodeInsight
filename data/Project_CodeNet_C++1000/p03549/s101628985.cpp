#include <bits/stdc++.h>
using namespace std;

int main(){
  long double n, m;
  cin >> n >> m;
  
  long double time = m*1900 + (n-m)*100;
  long double ans = 0;
  
  long double pro = pow(2, m);
  long double ntime = time, npro = 1 / pro;
  long double ex = ntime * npro;
  pro = 1 - npro;
  while(ex >= 0.001){
    ans += ex;
    ntime += time;
    npro *= pro;
    ex = ntime * npro;
  }
  
  cout << (long long)(ans+0.5) << endl;
}