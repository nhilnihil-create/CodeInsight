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
  string n;
  cin >> n;
  
  if(n[0] == n[1] && n[1] == n[2]){
    cout << "Yes" << endl;
  }
  else if(n[2] == n[3] && n[1] == n[2]) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
  return 0;
}
