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
using VP = vector<PII>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)
	//i=m -> n-1(昇順)
#define RREP(i,m,n) for(LL i=(m);i>=(n);i--)
	//i=m -> n(降順)

int main(){
  LL n;
  cin >> n;
  VLL l(n+10);
  l[0] = 2;
  l[1] = 1;
  
  REP(i,2,n+1){
    l[i] = l[i-1] + l[i-2];
  }
  
  cout << l[n] << endl;
  
  return 0;
}
