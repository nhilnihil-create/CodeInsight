#include <bits/stdc++.h>
using namespace std;

int main(){
  int d, g; cin >> d >> g;
  vector<int> p(d), c(d);
  for(int i = 0; i < d; i++){
    cin >> p[i] >> c[i];
  }
  int ans = 1001001001;
  for(int i = 0; i < (1<<d); i++){
    int sum = 0, ins = 0, num = 0;
    for(int j = 0; j < d; j++){
      if(!(i & (1<<j))) ins = j;
      else{
        sum += (j+1)*100*p[j] + c[j];
        num += p[j];
      }
    }
    if(sum < g){
      if(sum + (ins+1)*100*(p[ins]-1) < g) continue;
      else num += ((g-sum)+((ins+1)*100-1))/((ins+1)*100);
    }
    ans = min(ans, num);
  }
  cout << ans << endl;
}