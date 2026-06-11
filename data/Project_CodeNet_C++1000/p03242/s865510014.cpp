#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string n; cin >> n;
  rep(i,n.size()){
    if(n[i]=='1') n[i] = '9';
    else n[i] = '1';
  }

  cout << n << endl;
  
  return 0;
}
