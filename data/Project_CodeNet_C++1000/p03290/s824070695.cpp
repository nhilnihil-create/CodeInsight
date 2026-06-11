#include <bits/stdc++.h>
using namespace std;

int main(){
  int D,G;
  cin >> D >> G;
  vector<int> p(11),c(11);
  for(int i=0;i<D;i++) cin >> p.at(i) >> c.at(i);
  int res = 10000;
  for(int bit=0;bit<(1<<D);bit++){
    int ans = 0;
    int sum = 0;
    int rest_max =0;
    for(int i=0;i<D;i++){
      if(bit>>i&1){
        sum += c.at(i) + 100*(i+1)*p.at(i);
        ans += p.at(i);
      }else{
        rest_max = i;
      }
    }
    int si = 100*(rest_max+1);
    int need;
    if(G>sum){
      need = (G-sum+si-1)/si;
      if(need>p.at(rest_max)) continue;
      else ans += need;
    }
    res = min(res,ans);
  }
  cout << res << endl;
}