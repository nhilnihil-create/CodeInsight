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
  LL n,k,cur=1;
  cin >> n >> k;
  
  REP(i,0,n){
    if(cur >= k){
      cur += k;
    }
    else{
      cur *= 2;
    }
  }
  
  cout << cur << endl;
  
  return 0;
}
