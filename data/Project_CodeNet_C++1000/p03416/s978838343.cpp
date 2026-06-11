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
  LL a,b,ans=0;
  cin >> a >> b;
  
  REP(i,a,b+1){
    if(i/10000 == i%10 && (i/1000)%10 == (i/10)%10){
      ans++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
