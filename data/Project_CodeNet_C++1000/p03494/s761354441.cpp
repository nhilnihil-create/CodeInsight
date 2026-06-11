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
  LL n;
  cin >> n;
  VLL a(n),b(n,0);
  REP(i,0,n){
    cin >> a.at(i);
    while(a.at(i)%2 == 0){
      a.at(i) /= 2;
      b.at(i)++;
    }
  }
  
  sort(b.begin(),b.end());
  
  cout << b.at(0) << endl;
  
  return 0;
}
