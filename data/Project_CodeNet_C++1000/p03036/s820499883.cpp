#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int r,d,x2000; cin >> r >> d >> x2000;

  int x = x2000;
  rep(i,10){
    x = r*x-d;
    cout << x << endl;
  }
  
  return 0;
}
