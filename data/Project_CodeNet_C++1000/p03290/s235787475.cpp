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
  LL d,g,ans=1<<30;
  cin >> d >> g;
  VLL p(d+1), c(d+1);
  REP(i,1,d+1){
    cin >> p[i] >> c[i];
  }
  
  REP(i,0,1<<d){
    LL sum = 0;
    LL cnt = 0;
    REP(j,0,d){
      if(((i>>j)&1) == 1){
        sum += p[d-j] * (d-j) * 100 + c[d-j];
        cnt += p[d-j];
      }
    }
    if(sum >= g){
      ans = min(ans,cnt);
      continue;
    }
    REP(k,0,d){
      int out = (i>>k)&1;
      if(((i>>k)&1) == 0){
        LL sum_max = sum + (p[d-k]-1) * (d-k) * 100;
        if(sum_max < g){break;}
        while(sum < g){
          sum += (d-k) * 100;
          cnt++;
        }
        ans = min(ans,cnt);
        break;
      }
    }
  }   
  
  cout << ans << endl;
  
  return 0;
}
