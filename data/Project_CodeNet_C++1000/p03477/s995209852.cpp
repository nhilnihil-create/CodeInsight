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
  LL a,b,c,d;
  cin >> a >> b >> c >> d;
  
  if(a+b < c+d){
    cout << "Right" << endl;
  }
  else if(a+b > c+d){
    cout << "Left" << endl;
  }
  else {
    cout << "Balanced" << endl;
  }
  
  return 0;
}
