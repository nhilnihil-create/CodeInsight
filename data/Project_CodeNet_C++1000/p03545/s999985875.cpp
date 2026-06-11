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
  string s;
  cin >> s;
  VI a(4);
  REP(i,0,4){
    a[i] = s[i] - '0';
  }
  
  if(a[0]+a[1]+a[2]+a[3] == 7){
    cout << a[0] << "+" << a[1] << "+" << a[2] << "+" << a[3] << "=7" << endl;
    return 0;
  }
  if(a[0]+a[1]+a[2]-a[3] == 7){
    cout << a[0] << "+" << a[1] << "+" << a[2] << "-" << a[3] << "=7" << endl;
    return 0;
  }
  if(a[0]+a[1]-a[2]+a[3] == 7){
    cout << a[0] << "+" << a[1] << "-" << a[2] << "+" << a[3] << "=7" << endl;
    return 0;
  }
  if(a[0]+a[1]-a[2]-a[3] == 7){
    cout << a[0] << "+" << a[1] << "-" << a[2] << "-" << a[3] << "=7" << endl;
    return 0;
  }
  if(a[0]-a[1]+a[2]+a[3] == 7){
    cout << a[0] << "-" << a[1] << "+" << a[2] << "+" << a[3] << "=7" << endl;
    return 0;
  }
  if(a[0]-a[1]+a[2]-a[3] == 7){
    cout << a[0] << "-" << a[1] << "+" << a[2] << "-" << a[3] << "=7" << endl;
    return 0;
  }
  if(a[0]-a[1]-a[2]+a[3] == 7){
    cout << a[0] << "-" << a[1] << "-" << a[2] << "+" << a[3] << "=7" << endl;
    return 0;
  }
  
  return 0;
}
