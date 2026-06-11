#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using PLL = pair<LL,LL>;
using VPI = vector<PII>;
using VPL = vector<PLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(int i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  int n;
  cin >> n;
  VS s(n);
  VI p(n);
  vector<tuple<string,int,int>> tpl(n);
  REP(i,0,n){
    cin >> s[i] >> p[i];
    tpl[i] = make_tuple(s[i], 100-p[i], i+1);
  }
  
  sort(tpl.begin(),tpl.end());
  
  REP(i,0,n){
    cout << get<2>(tpl[i]) << endl;
  }
  
  return 0;
}
