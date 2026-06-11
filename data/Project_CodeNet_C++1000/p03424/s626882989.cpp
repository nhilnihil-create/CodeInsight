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
  int n;
  cin >> n;
  VS s(n);
  REP(i,0,n){
    cin >> s.at(i);
    if(s.at(i) == "Y"){
      cout << "Four" << endl;
      return 0;
    }
  }
  
  
  cout << "Three" << endl;
  
  return 0;
}
