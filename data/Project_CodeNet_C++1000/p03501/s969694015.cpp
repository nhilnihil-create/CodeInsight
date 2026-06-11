#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)

int main(){
  LL n,a,b;
  cin >> n >> a >> b;
  
  if(a*n < b){
    cout << a*n << endl;
  }
  else {
    cout << b << endl;
  }
  
  return 0;
}
