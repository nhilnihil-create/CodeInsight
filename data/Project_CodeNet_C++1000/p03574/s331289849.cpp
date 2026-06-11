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
  int h,w;
  cin >> h >> w;
  VVI che(h+10, VI(w+10,0));
  VS s(h),ans(h);
  REP(i,0,h){
    cin >> s.at(i);
    REP(j,0,w){
      ans.at(i) += "0";
    }
  }
  
  REP(i,0,h){
    REP(j,0,w){
      if(s.at(i)[j] == '#'){
        REP(a,i,i+3){
          REP(b,j,j+3){
            che.at(a).at(b)++;
          }
        }
        che.at(i+1).at(j+1) -= 1000;
      }
    }
  }
  REP(i,0,h){
    REP(j,0,w){
      if(che.at(i+1).at(j+1) >= 0){
        ans.at(i)[j] += che.at(i+1).at(j+1);
      }
      else{
        ans.at(i)[j] = '#';
      }
    }
  }
        
  REP(i,0,h){
    cout << ans.at(i) << endl;
  }
  
  return 0;
}
